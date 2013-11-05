#import "JSLocalization.h"

@implementation JSLocalization

NSString * const JSLocaleDidChangeNotification = @"JSLocaleDidChangeNotification";
static NSString * const CurrentLocaleStorageKey = @"JSLocalizationCurrentLocale";

static NSString *_currentLocale;
static NSBundle *_currentLocalizationBundle;

+ (void)load
{
    [super load];
    
    _currentLocale = [[NSUserDefaults standardUserDefaults] objectForKey:CurrentLocaleStorageKey];
    
    if (!_currentLocale) {
        _currentLocale = [self defaultLocale];
    }
    
    if (![self loadBundleForLocale:_currentLocale]) {
        _currentLocale = [self defaultLocale];
        [self loadBundleForLocale:_currentLocale];
    }
}

+ (NSString *)defaultLocale
{
    return [[NSLocale preferredLanguages] firstObject];
}

+ (BOOL)loadBundleForLocale:(NSString *)locale
{
    NSString *pathToLocalizationBundle = [[NSBundle mainBundle] pathForResource:locale ofType:@"lproj"];
    
    if (!pathToLocalizationBundle) {
        return NO;
    }
    
    _currentLocalizationBundle = [NSBundle bundleWithPath:pathToLocalizationBundle];
    
    return YES;
}

+ (BOOL)setCurrentLocale:(NSString *)locale
{
    if (!locale) {
        locale = [self defaultLocale];
    }
    
    if ([locale isEqualToString:_currentLocale]) {
        return YES;
    }
    
	if (![self loadBundleForLocale:locale]) {
        return NO;
    }
    
    _currentLocale = locale;
    
    [[NSNotificationCenter defaultCenter] postNotificationName:JSLocaleDidChangeNotification object:locale];
    
    return YES;
}

+ (NSString *)currentLocale
{
    return _currentLocale;
}

+ (NSString *)localizedStringForKey:(NSString *)key
{
	return [_currentLocalizationBundle localizedStringForKey:key value:@"" table:nil];
}

@end
