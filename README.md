# Supertree Games SDK
### Supertree Games는 모바일 게임의 크로스마케팅 플랫폼입니다.

## Unity Plugin
#### Unity3D용 IndieStar API를 소개합니다.
#### Unity Plugin (V 2.56): [Download](https://github.com/pass4u/IndieStar/blob/master/unity/superstargames_unitypackage_2.56.unitypackage)
#### Android Pulgin (V 2.56):[Download](https://github.com/pass4u/IndieStar/tree/master/unity/aos)
#### iOS Plugin (V 2.56):[Download](https://github.com/pass4u/IndieStar/tree/master/unity/ios)


#### 목차
> - [Unity iOS 설정](#chapter-2)
>  - [StartIndieStar 설정](#chapter-2-1)
>  - [PopupOnIndieStar 설정](#chapter-2-1)
>  - [MoreGameSimpleOnIndieStar 설정](#chapter-2-1)
>  - [PopupCloseHandler 등록](#chapter-2-4)
> - [Unity Android 설정](#chapter-3)
>  - [StartIndieStar 설정](#chapter-3-1)
>  - [PopupOnIndieStar 설정](#chapter-3-2)
>  - [MoreGameSimpleOnIndieStar 설정](#chapter-3-3)
>  - [PopupCloseHandler 등록](#chapter-3-4)
>  - [IndieStarView 설정](#chapter-3-4)
>  - [InstallReferrer 설정](#chapter-3-5)
> - [Android 라이브러리 메소드](#android)
> - [iOS 라이브러리 메소드](#ios)
> - [Release Note](#chapter-4)



<a id="chapter-2"></a>
### Unity iOS 설정
#### - IndieStarForIOS Class를 Component로 셋팅합니다.
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_1.png)

<a id="chapter-2-1"></a>
##### 1. StartIndieStar 설정
###### - IndieStar를 초기화 하는 과정으로, apple appid, IndieStar 등록 id, package name을 입력합니다. Unity의 Start 함수에 정의하는 것이 좋습니다. 최초 1회만 호출되도록 코드 추가 합니다.
###### parameter
> apple app id : "apple 앱 아이디" : string

> indiestar id : "indiestar 등록시 발급받은 아이디" : string

> package name : "패키지 네임" : string

    IndieStarForIOS.instance.StartIndieStar ("1099756918", "mAMhxd7sr6gqkFJej", "com.example.app");

<a id="chapter-2-2"></a>
##### 2. PopupOnIndieStar 설정(Android설정과 같음)
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_5.png)
###### - IndieStar 전면팝업을 띄우는 메서드 입니다.

    IndieStarForIOS.instance.PopupOnIndieStar();

<a id="chapter-2-3"></a>
##### 3. MoreGameSimpleOnIndieStar 설정(Android설정과 같음)
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_6.png)
###### - IndieStar 오퍼월을 띄우는 메서드 입니다.

    IndieStarForIOS.instance.MoreGameSimpleOnIndieStar();

<a id="chapter-2-4"></a>
##### 4. PopupCloseHandler 등록
###### - IndieStar의 모든 팝업이 닫힐때 호출될 콜백 메서드를 정의합니다.
###### parameter
> GameObject name : string

> Method name : string

        IndieStarForIOS.instance.RegisterPopupCloseHandler("Main Camera","PopupCloseHandler");
     
     
<a id="chapter-2-5"></a>
##### 5. GameNoticeOnIndieStar 설정(Android설정과 같음)
###### - IndieStar 특정 게임, 국가에 공지사항을 띄우는 메서드 입니다. Admin Server NoticeBanner에 등록되어있는 게임 패키지명 과 언어와 sdk를 사용하는 게임 패키지명 과 기기에 설정되어있는 언어가 맞아야지만 호출이 됩니다.

    IndieStarForIOS.instance.GameNoticeOnIndieStar();  
        
        
<a id="chapter-2-6"></a>
##### 6. GameShareOnIndieStar 설정
###### - IOS에서 Text를 공유하는 API호출하는 메서드 입니다.
###### - 공유한 Url을 모바일에서 클릭하면 항상 sdk를 사용한 게임에 스토어로 이동하고 이 메서드를 실행한 사람의 today,total,current_point값이 1증가합니다. 하루에 얻을수있는 포인트는 100point 입니다. today 포인트는 매일 00시00분00초 0으로 초기화 됩니다. 중복 클릭이 불가능 합니다(ex. A가 공유 B가 A의Url 10번 클릭하면 스토어로 이동은 되지만 A의 today,total,current_point는 1만증가)
###### parameter
> strUrl : store로 연결되는 url GetShareUrl의 return value
       

    IndieStarForIOS.instance.GameShareOnIndieStar("XX.XX.XX/XX/XX/key?=XXX"); 




<a id="chapter-2-7"></a>
##### 7. GetShareUrlOnIndieStar 설정
###### - 공유할 Url을 가져오는 메서드 입니다.
###### parameter
> aos_pack_name : 게임의 aos 번들 (SKU)명 (ex: com.slowpuppy.XXX)

> ios_apple_id : itunes connect apple id

###### return value
> string : "xxx.xxx.xxx/share/click/IOS?key=xxxxxxx"

    IndieStarForIOS.instance.GetShareUrlOnIndieStar("com.example.app", "1099756918");



       
<a id="chapter-2-8"></a>
##### 8. GetBalanceOnIndieStar 설정
###### - 게임내 Share Point를 받아오는 메서드 입니다.
###### parameter
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값

###### return value
> string : "today,current_point,total" (ex "1,1,1")

    IndieStarForIOS.instance.GetBalanceOnIndieStar("xxxxxxxxxxxxxxxxxxx");

       
<a id="chapter-2-9"></a>
##### 9. SharePointConsumeOnIndieStar 설정
###### - 게임내 Share Point를 차감하는 메서드 입니다.
###### - 가지고 있는 current_point값 만큼만 차감할 수 있습니다. 차감은 current_point만 감소합니다(ex.A의today=100, current_point=100, total=100 일때 100만큼 차감 => A의 남은 포인트 today=100, current_point=0, total=100)
###### parameter
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값
 
> iNum : 차감할 포인트

###### return value
> return value -1 : 구매실패 (ex. current_point = 100일때 101이상 차감하려고 할때)

> return value 양의정수 or 0 : 구매 후 남은 current_point 값

    IndieStarForIOS.instance.SharePointConsumeOnIndieStar("xxxxxxxxxxxxxxxxxxx", 1);

       
       
<a id="chapter-3"></a>
### Unity Android 설정
#### - IndieStarForAOS Class를 Component로 셋팅합니다.
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_1.png)

<a id="chapter-3-1"></a>
##### 1. StartIndieStar 설정
###### - IndieStar를 초기화 하는 과정으로 IndieStar 등록 id, package name을 입력합니다. Unity의 Start 함수에 정의하는 것이 좋습니다. 최초 1회만 호출되도록 코드 추가 합니다.
###### parameter

> indiestar id : "indiestar 등록시 발급받은 아이디"

> package name : "패키지 네임"

    IndieStarForAOS.instance.StartIndieStar ("mAMhxd7sr6gqkFJej", "com.example.app");

<a id="chapter-3-2"></a>    
##### 2. PopupOnIndieStar 설정(iOS설정과 같음)
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_2.png)

    IndieStarForAOS.instance.PopupOnIndieStar();
<a id="chapter-3-3"></a>
##### 3. MoreGameSimpleOnIndieStar 설정(iOS설정과 같음)
![Alt component 설정](https://github.com/pass4u/IndieStar/blob/master/res/api_3.png)

    IndieStarForAOS.instance.MoreGameSimpleOnIndieStar();

<a id="chapter-3-4"></a>
##### 4. PopupCloseHandler 등록
###### - IndieStar의 모든 팝업이 닫힐때 호출될 콜백 메서드를 정의합니다.
###### parameter
> GameObject name : string

> Method name : string


    IndieStarForAOS.instance.RegisterPopupCloseHandler("Main Camera","PopupCloseHandler");


<a id="chapter-3-5"></a>
##### 5. IndieStarView 설정
###### - IndieStarView Activity 를 AndroidManifest.xml에 추가합니다.
    <activity android:name="com.longtu.indiestar.IndieStarView" android:screenOrientation="sensorLandscape" android:theme="@android:style/Theme.Translucent"/>


<a id="chapter-3-6"></a>
##### 6. InstallReferrer 설정
###### - InstallReferrer 를 AndroidManifest.xml에 추가합니다.
    <receiver android:name="com.longtu.indiestar.InstallReferrerReceiver" android:exported="true">
      <intent-filter>
        <action android:name="com.android.vending.INSTALL_REFERRER" />
      </intent-filter>
    </receiver>


<a id="chapter-3-7"></a>
##### 7. GameNoticeOnIndieStar 설정(IOS설정과 같음)
###### - IndieStar 특정 게임, 국가에 공지사항을 띄우는 메서드 입니다. Admin Server NoticeBanner에 등록되어있는 게임 패키지명 과 언어와 sdk를 사용하는 게임 패키지명 과 기기에 설정되어있는 언어가 맞아야지만 호출이 됩니다.

    IndieStarForAOS.instance.GameNoticeOnIndieStar();
        
<a id="chapter-3-8"></a>
##### 8. ShareOnIndieStar 설정
###### - Android에서 Text를 공유하는 API호출하는 메서드 입니다.
###### - 공유한 Url을 모바일에서 클릭하면 항상 sdk를 사용한 게임에 스토어로 이동하고 이 메서드를 실행한 사람의 today,total,current_point값이 1증가합니다. 하루에 얻을수있는 포인트는 100point 입니다. today 포인트는 매일 00시00분00초 0으로 초기화 됩니다. 중복 클릭이 불가능 합니다(ex. A가 공유 B가 A의Url 10번 클릭하면 스토어로 이동은 되지만 A의 today,total,current_point는 1만증가)
###### parameter
> strUrl : store로 연결되는 url GetShareUrl의 return value

    IndieStarForAOS.instance.ShareOnIndieStar("XX.XX.XX/XX/XX/key?=XXX");


<a id="chapter-3-9"></a>
##### 9. GetShareUrlOnIndieStar 설정
###### - 공유할 Url을 가져오는 메서드 입니다.
###### parameter
> aos_pack_name : 게임의 aos 번들 (SKU)명 (ex: com.slowpuppy.XXX)

> ios_apple_id : itunes connect apple id

###### return value
> string : "xxx.xxx.xxx/share/click/AOS?key=xxxxxxx"

    IndieStarForAOS.instance.GetShareUrlOnIndieStar("com.example.app", "1099756918");

       
<a id="chapter-3-10"></a>
##### 10. GetBalanceOnIndieStar 설정
###### - 게임내 Share Point를 받아오는 메서드 입니다.
###### parameter
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값

###### return value
> string : "today,current_point,total" (ex "1,1,1")

    IndieStarForAOS.instance.GetBalanceOnIndieStar("xxxxxxxxxxxxxxxxxxx"); 
      
       
<a id="chapter-3-11"></a>
##### 11. SharePointConsumeOnIndieStar 설정
###### - 게임내 Share Point를 차감하는 메서드 입니다.
###### - 가지고 있는 current_point값 만큼만 차감할 수 있습니다. 차감은 current_point만 감소합니다(ex.A의today=100, current_point=100, total=100 일때 100만큼 차감 => A의 남은 포인트 today=100, current_point=0, total=100)
###### parameter
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값
 
> iNum : 차감할 포인트

###### return value
> return value -1 : 구매실패 (ex. current_point = 100일때 101이상 차감하려고 할때)

> return value 양의정수 or 0 : 구매 후 남은 current_point 값






    IndieStarForAOS.instance.SharePointConsumeOnIndieStar("xxxxxxxxxxxxxxxxxxx", 1);  






<a id="android"></a>

#### Jar 
#### Android Pulgin :[Download](https://github.com/pass4u/IndieStar/tree/master/unity/aos)


##### Init
    void Start(String app_id, String package_name)
> app_id : Superstars games 에서 발급한 id

> package_name : 패키지명


##### 창 닫힘 이벤트 콜백 (Unity에서 사용)
    void RegisterCloseHandler(String class_name, String method_name)
> class_name : 이벤트를 수신할 game object

> method_name : 이벤트를 수신할 method


##### Interstitial (전면배너)
    void Popup(Context mContext)

##### More Game 팝업 (채널링내 다른 게임 목록제공)
    void MoreGameSimple(Context mContext)
    
##### Game Notice 팝업 (특정 게임에 국가별로 공지사항 등록)
    void GameNoticePopup(Context mContext)
    
##### 공유하기 (공유할 목록을 띄움)
    void GameShare(Context mContext, String strUrl)
> strUrl : store로 연결되는 url GetShareUrl의 return value

##### Share Url Get (공유할 url 얻어옴)
    String GetShareUrl(Context mContext, String aos_pack_name, String ios_apple_id)
> aos_pack_name : 게임의 aos 번들 (SKU)명 (ex: com.slowpuppy.XXX)

> ios_apple_id : itunes connect apple id

> return string : "xx.xx.xx/share/click/AOS?key=xxxxx"

##### Consume (포인트 차감)
    int Consume(String strKey, int iNum)
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값

> iNum : 차감할 포인트

> return value -1 : 구매실패 (ex. current_point = 100일때 101이상 차감하려고 할때)

> return value 양의정수 or 0 : 구매 후 남은 current_point 값

##### GetBalance (Today, Current Point, Total)
    String GetBalance(String strKey)
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값    

> return string : "today,current_point,total" (ex "1,1,1")

<a id="ios"></a>
#### iOS 라이브러리 (.a) 
#### iOS Plugin :[Download](https://github.com/pass4u/IndieStar/tree/master/unity/ios)

##### Init
    (void)IndieStarStart:(NSString*)_app_id indiestar_id:(NSString*)_indiestar_id package_name:(NSString*)_package_name
> _app_id : itunes connect apple id

> _indiestar_id : Superstar games에서 발급받은 id

> _package_name : 게임의 ios 번들 (SKU)명 (ex: com.slowpuppy.XXX.ios)

  
  
  
##### 창 닫힘 이벤트 콜백 (Unity에서 사용)
    (void)RegisterCloseHandlerFunc:(const char*)_class_name method:(const char*)_method
> _class_name : 이벤트를 수신할 game object 

> _method : 이벤트를 수신할 method


##### Interstitial (전면배너)
    -(void)IndieStarAd

##### More Game 팝업 (채널링내 다른 게임 목록제공)
    -(void)IndieStarMoreGameSimple
    
##### Game Notice 팝업 (특정 게임에 국가별로 공지사항 등록)
    -(void)IndieStarGameNotice
    
##### 공유하기 (공유할 목록을 띄움)
    -(void)GameShare:(NSString*)strUrl
> strUrl : store로 연결되는 url GetShareUrl의 return value

##### Share Url Get (공유할 url 얻어옴)
    -(char*) GetShareUrl : (NSString*)aos_pack_name:(NSString*)ios_apple_id
> aos_pack_name : 게임의 aos 번들 (SKU)명 (ex: com.slowpuppy.XXX)

> ios_apple_id : itunes connect apple id

> return string : "xx.xx.xx/share/click/IOS?key=xxxxx"

##### Consume (포인트 차감)
    -(int) Consume:(NSString*)strKey:(int)iNum
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값

> iNum : 차감할 포인트

> return value -1 : 구매실패 (ex. current_point = 100일때 101이상 차감하려고 할때)

> return value 양의정수 or 0 : 구매 후 남은 current_point 값

##### GetBalance (Today, Current Point, Total)
    -(char*) GetBalance : (NSString*)strKey
> strKey : 암호화된 key GetShareUrl의 return value 중 key의 값

> return string : "today,current_point,total" (ex "1,1,1")

<a id="chapter-4"></a>
#### Release note
##### V2.1 - 2017.02.23
###### - Android IndieStar 팝업 실행시 Crash 수정(AOS 5.0이상에서 발생)

##### V2.2 - 2017.03.02
###### - Android IndieStar 팝업실행 실행중 Back버튼시 close handler 호출

##### V2.3 - 2017.03,17
###### - SDK 서버 주소 변경

##### V2.4 - 2017.03,30
###### - 오늘만보기 기능추가됨

##### V2.41 (Unity/iOS) - 2017.03,30
###### - Xcode Build시 architecture error fix

##### V2.42 (Unity) -2017.4.8
###### iOS빌드 지원

##### v2.45
###### - 활성배너가 없을때 배너창이 열리지않도록 자동처리됨.
###### - 자기게임은 배너에서 제외됨.

##### v2.46 
###### - 오늘만보기체크 이후 빈액티비티가 잠깐 뜰수도 있는 이슈 fix

##### v2.47 
###### - 세로배너지원

##### v2.48 
###### - adroid  playstore로 연결안되는 이슈 fix

##### v2.48 
###### - android insatll referrer 체크 이슈  fix

##### v2.52 
###### - android,ios banner scale fix

##### v2.53 
###### - 게임 공지사항 배너 추가
###### - 공유하기 기능 

##### v2.54 
###### - 누적된 total 추가("today,current_point,total")

##### v2.55 
###### - sdk 서버 주소 변경

##### v2.56
###### - 공유하기, 게임공지사항 국가별 등록(default : 영어)
