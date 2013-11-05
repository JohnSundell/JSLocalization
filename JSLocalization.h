#import <Foundation/Foundation.h>

/**
 *  Macro to obtain the dynamically localized string
 *  for a key.
 *
 *  @param key A string mapping to a key in the
 *  Localizable.Strings files for the app.
 */
#define JSLocalizedString(key) [JSLocalization localizedStringForKey:key]

/**
 *  Name of the NSNotification sent out when the locale was
 *  changed using +setCurrentLocale:.
 *
 *  @discussion The object attached to the NSNotification
 *  will be the locale that was just set.
 */
extern NSString * const JSLocaleDidChangeNotification;

/**
 *  Class that enables iOS app localization with the
 *  ability to dynamically switch locale at runtime,
 *  without restarting the app.
 */
@interface JSLocalization : NSObject

/**
 *  Set the locale to use when localizing strings
 *  using +localizedStringForKey or JSLocalizedString.
 *
 *  @param locale The locale (a string identifier matching
 *  a lproj bundle available in your app bundle) the app
 *  should change to. Passing a non-nil string will cause
 *  the deault locale set by the user in Settings to
 *  be overridden, passing nil will reset the locale
 *  to the default system-wide one.
 *
 *  @return A BOOL indicating if the locale was
 *  successfully changed. A typical reason for
 *  failing would be that a lproj bundle does not
 *  exist for the specified locale. Attempting to
 *  set the same locale as already is the current
 *  will cause this method to return YES.
 *
 *  @discussion The set locale will be persisted in
 *  NSUserDefaults.
 *
 *  A NSNotification with the name
 *  JSLocaleDidChangeNotification is sent out
 *  when the locale is changed. See the documentation
 *  for JSLocaleDidChangeNotification for more info.
 */
+ (BOOL)setCurrentLocale:(NSString *)locale;

/**
 *  Return the current locale used this class.
 *
 *  @discussion If no locale has been set using
 *  this class, the default system-wide locale
 *  is returned.
 */
+ (NSString *)currentLocale;

/**
 *  Return the localized string for a key.
 *
 *  @param key A string mapping to a key in the
 *  Localizable.Strings files for the app.
 *
 *  @discussion See the JSLocalizedString macro for
 *  an easy way to use this API.
 */
+ (NSString *)localizedStringForKey:(NSString *)key;

@end
