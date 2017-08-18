//
//  IndieStar.h
//  IndieStar
//
//  Created by brian on 2017. 2. 3..
//  Copyright © 2017년 brian. All rights reserved.
//
//
//  IndiStarCrosswall.h
//  IndiStarBox/Users/pawa/indiestar-ios/IndieStar/IndieStar/IndieStar.h
//
//  Created by devman on 2016. 11. 29..
//  Copyright © 2016년 longtu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonDigest.h>
#define UNITY_INDISTAR


@interface IndieStar : NSObject<UIWebViewDelegate>{
    UIViewController *vc;
    UIWebView* webView;
    NSString *app_id;
    NSString *indiestar_id;
    NSString *package_name;
    NSString *UID;
    
    
    NSString* m_strServerUrl;
    NSString* m_strAdminServerUrl;
    
    //close handler
    NSString* class_name;
    NSString* method_name;
    
}


- (id)init;
- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request
 navigationType:(UIWebViewNavigationType)navigationType;

+ (void) initSDK: (UIViewController*) gameViewController;
+ (IndieStar *)sharedInstance;

-(void)RegisterCloseHandlerFunc:(const char*)_class_name method:(const char*)_method;
-(void)IndieStarStart:(NSString*)_app_id indiestar_id:(NSString*)_indiestar_id package_name:(NSString*)_package_name;
-(void)IndieStarMoreGameSimple;
-(void)IndieStarAd;
-(void)IndieStarGameNotice;
-(void)GameShare:(NSString*)strUrl;
-(char*) GetShareUrl : (NSString*)aos_pack_name:(NSString*)ios_apple_id;
-(int) Consume:(NSString*)strKey:(int)iNum;
-(char*) GetBalance : (NSString*)strKey;


-(char*) StringCopy:(const char*)strSrc;
- (NSString *)getDeviceUUID;
-(NSString*)getMD5:(NSString*)srcStr;



@end

#ifdef UNITY_INDISTAR
extern "C"{
    extern void UnitySendMessage(const char* obj, const char* method, const char* msg);
    extern UIViewController * UnityGetGLViewController();
    
}
#endif
