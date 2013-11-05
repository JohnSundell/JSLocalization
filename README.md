JSLocalization
==============

#### Let your users change the language of your app without restarting it

* Dynamically localize your app, allowing the locale to be changed at runtime.
* Provides APIs for setting the locale, as well as retrieving the localized string for a key, similar to NSLocalizedString.
* Useful when you want to provide an in-app language selection, to allow your users to pick a different language than the system-wide default for your app.

#### Here's how to use JSLocalization:

##### Use JSLocalization to obtain your localized strings

```objective-c
myLabel.text = JSLocalizedString(@"MyLabelText");
```

##### Use +setCurrentLocale: to change the locale
```objective-c
// Change the locale to Swedish
[JSLocalization setCurrentLocale:@"sv-SE"];
```

The parameter passed to +setCurrentLocale: must match the name of a lproj localization bundle available in your app's bundle.

##### Use the JSLocaleDidChangeNotification NSNotification to respond to changes in locale in your views
```objective-c
[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(localeDidChange:) name:JSLocaleDidChangeNotification object:nil];

- (void)localeDidChange:(NSNotification *)notification
{
	NSLog(@"Locale changed to: %@", notification.object);

	// Update label text to match new locale
	self.myLabel.text = JSLocalizedString(@"MyLabelText");
}
```

#### Hope that you'll enjoy using JSLocalization!

Why not give me a shout on Twitter: [@johnsundell](https://twitter.com/johnsundell)