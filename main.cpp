#ifdef WINVER
   #undef WINVER
 #endif
#define WINVER 0x500


#ifdef _WIN32_WINNT
   #undef _WIN32_WINNT
 #endif
#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#define GAME_DELAY_TIME 150
#define KEY_BOARD_UPDATE 2
#define ADD_BONUS_NUMBER 2

#define MAIN_MENU    0
#define BUILD_LEVEL  1
#define LOAD_LEVEL   2
#define GAME         3
#define GAME_RESULTS 4
#define GAME_OVER    5
#define SETINGS 6

#define BRICK_PLATE           0
#define BRICK_HALF_1_PLATE    1
#define BRICK_HALF_2_PLATE    2
#define BRICK_HALF_3_PLATE    3
#define BRICK_HALF_4_PLATE    4
#define METAL_PLATE           5
#define METAL_HALF_1_PLATE    6
#define METAL_HALF_2_PLATE    7
#define METAL_HALF_3_PLATE    8
#define METAL_HALF_4_PLATE    9
#define ROAD_PLATE            10
#define WATER_PLATE           11
#define TREES_PLATE           12
#define ISE_PLATE             13
#define BASE_PLATE            14
#define SPECIAL_ROAD_PLATE    15
#define SPECIAL_BRICK_1_PLATE 16
#define SPECIAL_BRICK_2_PLATE 17
#define SPECIAL_BRICK_3_PLATE 18
#define SPECIAL_BRICK_4_PLATE 19
#define SPECIAL_BRICK_5_PLATE 20

#define BRICK  0
#define METAL  1
#define WATER1 2
#define WATER2 3
#define WATER3 4
#define WATER4 5
#define ROAD   6
#define TREE   7
#define ISE1   8
#define ISE2   9
#define ISE3   10
#define ISE4   11
#define BASE1  12
#define BASE2  13
#define BASE3  14
#define BASE4  15



#define GAMER_SHOT 0
#define ENEMY_SHOT 1
#define VOID_SHOT  2

#define GAMER_SHOT_DETONATION 0
#define ENEMY_SHOT_DETONATION 1
#define TANK_DETONATION       2

#define LVL1_1_TANK 0
#define LVL1_2_TANK 1
#define LVL2_1_TANK 2
#define LVL2_2_TANK 3
#define LVL3_1_TANK 4
#define LVL3_2_TANK 5
#define LVL4_1_TANK 6
#define LVL4_2_TANK 7
#define LT_TANK     8
#define ST_TANK     9
#define TT_TANK     12

#define EASY 1
#define MEDIUM 2
#define HARD 3

#define GAMER1_LVL_BONUS 0
#define GAMER2_LVL_BONUS 1
#define GAMER1_ARMOR_BONUS 2
#define GAMER2_ARMOR_BONUS 3
#define TIME_BONUS 4
#define BASE_BONUS 5
#define ENEMIES_BONUS 6
#define RESPAWN_BONUS 7

#define WAY_POINT 0
#define ROAD_POINT 1
#define WALL_POINT 2
#define DESTROYABLE_WALL_POINT 3

#include<string>
#include <tchar.h>
#include <windows.h>
#include<iostream>
#include<chrono>
#include<thread>
#include<vector>
#include<mmsystem.h>
#include<fstream>
#include<cmath>



    using namespace std;
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);


TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
    HBITMAP images;
    void saveLevel(int n);
    bool MUSIC = false;

    class Setings{
        public:
        bool music;
        int delay;
        void load(){
        ifstream file;
        file.open("resurses\\setings\\setings.txt");
        if(!file.is_open()){

        }else{

        string m;
        file>>m;
        file>>delay;
        if(m=="on"){music=true;}else{music=false;}
        }
        file.close();
        }
        void save(){
        ofstream file;
        file.open("resurses\\setings\\setings.txt");
        if(file.is_open()){

            file<<(music?"on":"off")<<"\n"<<delay;

        }
        file.close();
        }
    };
    Setings setings;
    void setColor(HDC *hdc,int r,int g,int b);
    class Texture{
        public:
    short int r[160][520];
    short int g[160][520];
    short int b[160][520];
    void draw(HDC *hdc,int x,int y,int w,int h,int sx,int sy){
    int i=0,j=0;
    while(i<w){
        while(j<h){

                if((*this).r[i+sx][j+sy]>=0){

         setColor(hdc,(*this).r[i+sx][j+sy],(*this).g[i+sx][j+sy],(*this).b[i+sx][j+sy]);
         Rectangle(*hdc,x+i-1,y+j-1,x+i+1,y+j+1);
          }
        j++;}
        j=0;
        i++;
    }
    }
    void create(HDC *hdc,int x,int y,int r,int g,int b){
    HDC dc = CreateCompatibleDC(*hdc);
    SelectObject(dc,images);
    int i=0,j=0;
    while(i<160){
        while(j<520){
         COLORREF a = GetPixel(dc,i+x,j+y);
         int R = GetRValue(a),G = GetGValue(a),B = GetBValue(a);
         (*this).r[i][j] = (R==r&&B==b&&G==g)?-1:R;
        (*this).g[i][j] = G;
        (*this).b[i][j] = B;
        setColor(hdc,R,G,B);
        Rectangle(*hdc,i-1,j-1,i+1,j+1);
        j++;}
        j=0;
        i++;
    }
    DeleteDC(dc);
    }
    };

    class Music{
    public:
    bool m1 = false;
    string p1 = "";
    void f1(){
    while(true){
        if(p1!=""){
            m1 = true;
            PlaySound(p1.c_str(),0,SND_SYNC);
            PlaySound(NULL,NULL,SND_SYNC);
            m1 = false;
            p1 = "";
        }
    }

    }



    int play(string u){



    if(!m1&&MUSIC&&setings.music){p1 = u;return 0;}


    }

    };

    Music music;
    Texture tankTexture;
    Texture eventAndBonusTexture;

    void musicF(){
    music.f1();
    }
    void Main(HWND *hwnd);

    void delay(int time){
    this_thread::sleep_for(chrono::milliseconds(time));
    }

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;


    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);


    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;


    if (!RegisterClassEx (&wincl))
        return 0;


    hwnd = CreateWindowEx (
           0,
           szClassName,
           _T("Танчики"),
           WS_OVERLAPPEDWINDOW,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           544,
           375,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );


    ShowWindow (hwnd, nCmdShow);
    thread th(Main,&hwnd);
     th.detach();
     thread musicth(musicF);
     musicth.detach();
    while (GetMessage (&messages, NULL, 0, 0))
    {

        TranslateMessage(&messages);

        DispatchMessage(&messages);
    }


    return messages.wParam;
}


    //predefinitions
    class Scene;
    class Animation;
    class InputMapPlate;
    class Level;
    class Cell;
    class Game;
    void loop(HWND *hwnd,HDC *hdc);

    void activateScene(HWND *hwnd,int scene);
    void createExemplePlates();
    void createLevelMap(int level,InputMapPlate (&plates)[13][13]);
    void setup();
    //predefinitions
    //global variables

    struct KillsInfo{
    short lt;
    short st;
    short tt;
    };

    KillsInfo killsInfo[2];

    int activatedScene=MAIN_MENU,
    lastScene=MAIN_MENU,
    predictionActivationScene=0,
    loadingLevel=0,
    players = 2,
    activatedLevel = 0;

    //global variables
    //functions for scenes
    int width(HWND *hwnd){
      RECT rect;
        GetWindowRect(*hwnd,&rect);
        return rect.right-rect.left;
    }
    int height(HWND *hwnd){
       RECT rect;
        GetWindowRect(*hwnd,&rect);
        return rect.bottom-rect.top;
    }

    //functions for scenes

    //classes
    class Animation{
    public:
    vector<int> var;
    int progres;
    int time;
    void (*script)(HWND *hwnd,HDC *hdc);
    };
    class Scene{
    public :
        vector<int>var;
        Animation *anim;
        int width;
        int height;
        int lastWidth=0;
        int lastHeight=0;
        void (*setup)(HWND *hwnd);
        void (*script)(HWND *hwnd,HDC *hdc);
        void (*draw)(HDC *hdc);
        void (*button)(int x,int y);
    };
    class InputMapPlate{
    public:
    int type;
    int x;
    int y;
    bool redraw = false;
    bool touch(int x,int y){
    return (x>(*this).x&&x<(*this).x+40&&y>(*this).y&&y<(*this).y+40);
    }
    void draw(HDC*hdc,int x,int y){
    (*this).x=x;
    (*this).y=y;

    HDC hMemDC=CreateCompatibleDC(*hdc);
    SelectObject(hMemDC,images);
    switch((*this).type){
    case BRICK_PLATE:
    BitBlt(*hdc,x,y,40,40,hMemDC,80,330,SRCCOPY);
    break;
    case BRICK_HALF_1_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y,40,20,hMemDC,80,330,SRCCOPY);
    break ;
    case BRICK_HALF_2_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x+20,y,20,40,hMemDC,80,330,SRCCOPY);
    break ;
    case BRICK_HALF_3_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y+20,40,20,hMemDC,80,330,SRCCOPY);
    break;
    case BRICK_HALF_4_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y,20,40,hMemDC,80,330,SRCCOPY);
    break;
    case METAL_PLATE:

    BitBlt(*hdc,x,y,40,40,hMemDC,40,330,SRCCOPY);

    break;
    case METAL_HALF_1_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y,40,20,hMemDC,40,330,SRCCOPY);
    break;
    case METAL_HALF_2_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x+20,y,20,40,hMemDC,40,330,SRCCOPY);
    break;
    case METAL_HALF_3_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y+20,40,20,hMemDC,40,330,SRCCOPY);
    break;
    case METAL_HALF_4_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y,20,40,hMemDC,40,330,SRCCOPY);
    break;
    case ROAD_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    break;
    case WATER_PLATE:
    BitBlt(*hdc,x,y,40,40,hMemDC,120,330,SRCCOPY);
    break;
    case TREES_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x+5,y,10,5,hMemDC,205,330,SRCCOPY);
    BitBlt(*hdc,x+5,y+15,10,5,hMemDC,205,345,SRCCOPY);
    BitBlt(*hdc,x,y+5,5,10,hMemDC,200,335,SRCCOPY);
    BitBlt(*hdc,x+15,y+5,5,10,hMemDC,215,335,SRCCOPY);
    BitBlt(*hdc,x+5,y+5,10,10,hMemDC,205,335,SRCCOPY);
    x+=20;
    BitBlt(*hdc,x+5,y,10,5,hMemDC,205,330,SRCCOPY);
    BitBlt(*hdc,x+5,y+15,10,5,hMemDC,205,345,SRCCOPY);
    BitBlt(*hdc,x,y+5,5,10,hMemDC,200,335,SRCCOPY);
    BitBlt(*hdc,x+15,y+5,5,10,hMemDC,215,335,SRCCOPY);
    BitBlt(*hdc,x+5,y+5,10,10,hMemDC,205,335,SRCCOPY);
    x-=20;y+=20;
    BitBlt(*hdc,x+5,y,10,5,hMemDC,205,330,SRCCOPY);
    BitBlt(*hdc,x+5,y+15,10,5,hMemDC,205,345,SRCCOPY);
    BitBlt(*hdc,x,y+5,5,10,hMemDC,200,335,SRCCOPY);
    BitBlt(*hdc,x+15,y+5,5,10,hMemDC,215,335,SRCCOPY);
    BitBlt(*hdc,x+5,y+5,10,10,hMemDC,205,335,SRCCOPY);
    x+=20;
    BitBlt(*hdc,x+5,y,10,5,hMemDC,205,330,SRCCOPY);
    BitBlt(*hdc,x+5,y+15,10,5,hMemDC,205,345,SRCCOPY);
    BitBlt(*hdc,x,y+5,5,10,hMemDC,200,335,SRCCOPY);
    BitBlt(*hdc,x+15,y+5,5,10,hMemDC,215,335,SRCCOPY);
    BitBlt(*hdc,x+5,y+5,10,10,hMemDC,205,335,SRCCOPY);
    break;
    case ISE_PLATE:
    BitBlt(*hdc,x,y,40,40,hMemDC,160,330,SRCCOPY);
    break;
    case SPECIAL_ROAD_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    break;
    case BASE_PLATE:
    BitBlt(*hdc,x,y,40,40,hMemDC,240,330,SRCCOPY);
    break;
    case SPECIAL_BRICK_1_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x+20,y,20,40,hMemDC,80,330,SRCCOPY);
    break;
    case SPECIAL_BRICK_2_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y,20,40,hMemDC,80,330,SRCCOPY);
    break;
    case SPECIAL_BRICK_3_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y+20,40,20,hMemDC,80,330,SRCCOPY);
    break;
    case SPECIAL_BRICK_4_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y+20,40,20,hMemDC,80,330,SRCCOPY);
    Rectangle(*hdc,x,y,x+20,y+40);
    break;
    case SPECIAL_BRICK_5_PLATE:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+40,y+40);
    BitBlt(*hdc,x,y+20,40,20,hMemDC,80,330,SRCCOPY);
    Rectangle(*hdc,x+20,y,x+40,y+40);
    break;
    }
    DeleteDC(hMemDC);
    }
    };
    class Cell{
    public:
    int x;
    int y;
    bool redraw = true;
    int type = BRICK;
    vector<int> body = {1,1,1,1};
    void destroy(int side,int tankType){
    Cell &c = (*this);
    switch((*this).type){
    case BRICK:
    switch(side){
    case 1:
    if(c.body[2]==1||c.body[3]==1){c.body[2]=c.body[3]=0;}else{c.body[0]=c.body[1]=0;}
    break;
    case 3:
    if(c.body[0]==1||c.body[1]==1){c.body[0]=c.body[1]=0;}else{c.body[2]=c.body[3]=0;}
    break;
    case 2:
    if(c.body[0]==1||c.body[2]==1){c.body[2]=c.body[0]=0;}else{c.body[1]=c.body[3]=0;}
    break;
    case 4:
    if(c.body[1]==1||c.body[3]==1){c.body[1]=c.body[3]=0;}else{c.body[0]=c.body[2]=0;}
    break;
    }
    if(c.body[0]==0&&c.body[1]==0&&c.body[2]==0&&c.body[3]==0){(*this).type = ROAD;}

    break;
    case METAL:

    if(!(tankType==LVL4_1_TANK||tankType==LVL4_2_TANK)){
    break;}
    case BASE1:
    case BASE2:
    case BASE3:
    case BASE4:
    (*this).type = ROAD;
    break;
    }
    }
    void draw(HDC *hdc,int x,int y){
    (*this).redraw=false;
    (*this).x = x,(*this).y = y;
    HDC hMemDC=CreateCompatibleDC(*hdc);
    SelectObject(hMemDC,images);
    switch((*this).type){
    case ROAD:
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+20,y+20);
    break;
    case BRICK:
    //BitBlt(*hdc,x,y,20,20,hMemDC,80,330,SRCCOPY);
    setColor(hdc,10,10,10);
    Rectangle(*hdc,x,y,x+20,y+20);
    if((*this).body[0]==1){BitBlt(*hdc,x,y,10,10,hMemDC,80,330,SRCCOPY);}
    if((*this).body[1]==1){BitBlt(*hdc,x+10,y,10,10,hMemDC,90,330,SRCCOPY);}
    if((*this).body[2]==1){BitBlt(*hdc,x,y+10,10,10,hMemDC,80,340,SRCCOPY);}
    if((*this).body[3]==1){BitBlt(*hdc,x+10,y+10,10,10,hMemDC,90,340,SRCCOPY);}
    break;
    case METAL:
    BitBlt(*hdc,x,y,20,20,hMemDC,40,330,SRCCOPY);
    break;
    case TREE:

    BitBlt(*hdc,x+5,y,10,5,hMemDC,205,330,SRCCOPY);
    BitBlt(*hdc,x+5,y+15,10,5,hMemDC,205,345,SRCCOPY);
    BitBlt(*hdc,x,y+5,5,10,hMemDC,200,335,SRCCOPY);
    BitBlt(*hdc,x+15,y+5,5,10,hMemDC,215,335,SRCCOPY);
    BitBlt(*hdc,x+5,y+5,10,10,hMemDC,205,335,SRCCOPY);
    break;
    case WATER1:
    BitBlt(*hdc,x,y,20,20,hMemDC,140,330,SRCCOPY);
    break;
    case WATER2:
    BitBlt(*hdc,x,y,20,20,hMemDC,120,330,SRCCOPY);
    break;
    case WATER3:
    BitBlt(*hdc,x,y,20,20,hMemDC,120,350,SRCCOPY);
    break;
    case WATER4:
    BitBlt(*hdc,x,y,20,20,hMemDC,140,350,SRCCOPY);
    break;
    case ISE1 :
    BitBlt(*hdc,x,y,20,20,hMemDC,160,330,SRCCOPY);
    break;
    case ISE2 :
    BitBlt(*hdc,x,y,20,20,hMemDC,180,330,SRCCOPY);
    break;
    case ISE3 :
    BitBlt(*hdc,x,y,20,20,hMemDC,160,350,SRCCOPY);
    break;
    case ISE4 :
    BitBlt(*hdc,x,y,20,20,hMemDC,180,350,SRCCOPY);
    break;
    case BASE1 :
    BitBlt(*hdc,x,y,20,20,hMemDC,240,330,SRCCOPY);
    break;
    case BASE2 :
    BitBlt(*hdc,x,y,20,20,hMemDC,260,330,SRCCOPY);
    break;
    case BASE3 :
    BitBlt(*hdc,x,y,20,20,hMemDC,240,350,SRCCOPY);
    break;
    case BASE4 :
    BitBlt(*hdc,x,y,20,20,hMemDC,260,350,SRCCOPY);
    break;
    }
    DeleteDC(hMemDC);
    //setColor(hdc,255,0,0);
   // Rectangle(*hdc,x,y,x+20,y+20);

    }
    };
    Scene scenes[7];
    class Level{
    public:
    Cell map[26][26];
    int enemyType = 1;
    void setRedraw(int n,int m){
    (*this).map[n][m].redraw=true;
    }
    void drawBottom(HDC *hdc){
        Scene &scn = scenes[activatedScene];
    int i = 26,j=26;
    while(i>0){
        while(j>0){
            if((*this).map[i-1][j-1].type!=TREE){(*this).map[i-1][j-1].draw(hdc,scn.width/2-260+(i-1)*20,scn.height/2-260+(j-1)*20);}
            j--;
        }
        j=26;
        i--;
    }
    }
    void drawTrees(HDC *hdc){
    Scene &scn = scenes[activatedScene];

    int i = 26,j=26;
    while(i>0){
        while(j>0){
            if((*this).map[i-1][j-1].type==TREE){(*this).map[i-1][j-1].draw(hdc,scn.width/2-260+(i-1)*20,scn.height/2-260+(j-1)*20);}
            j--;
        }
        j=26;
        i--;
    }
    }
    };

    //classes
    //objects

    Animation animations[6];
    InputMapPlate exemplesPlates[8];
    InputMapPlate buildingLevelMap[13][13];
    Level levels[21];

    //objects
    //Animations for scenes
    void animationMainMenu(HWND*hwnd,HDC*hdc){}
    void animationCreateLevel(HWND*hwnd,HDC*hdc){}
    void animationGameOver(HWND*hwnd,HDC*hdc){}
    void animationLevelLoad(HWND*hwnd,HDC*hdc){}
    void animationGame(HWND*hwnd,HDC*hdc){}
    void animationGameResults(HWND*hwnd,HDC*hdc){}
    //Animations for scenes
    //methods for scenes
    void setupMainMenu(HWND *hwnd){

    }
    void scriptMainMenu(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[activatedScene];
    scn.width  = width(hwnd);
    scn.height = height(hwnd);
    scn.draw(hdc);
    }
    void drawMainMenu(HDC *hdc){
    Scene &scn = scenes[activatedScene];
    setColor(hdc,0,0,0);
    Rectangle(*hdc,0,0,scn.width,scn.height);
    HDC hMemDC=CreateCompatibleDC(*hdc);
    SelectObject(hMemDC,images);
    BitBlt(*hdc,scn.width/2-100,350,200,30,hMemDC,0,0,SRCCOPY);
    BitBlt(*hdc,scn.width/2-100,400,200,30,hMemDC,200,0,SRCCOPY);
    BitBlt(*hdc,scn.width/2-100,450,200,30,hMemDC,370,0,SRCCOPY);
    BitBlt(*hdc,scn.width/2-250,40,500,300,hMemDC,0,30,SRCCOPY);
    BitBlt(*hdc,scn.width/2-100-30,500,200,30,hMemDC,550,0,SRCCOPY);
    DeleteDC(hMemDC);
    }
    void buttonMainMenu(int x,int y){
    Scene &scn = scenes[activatedScene];

    if(x>scn.width/2-100&&x<scn.width/2+100&&y>350&&y<380){players=1;predictionActivationScene=LOAD_LEVEL;players=1;activatedLevel=1;}
    if(x>scn.width/2-100&&x<scn.width/2+100&&y>400&&y<430){players=2;predictionActivationScene=LOAD_LEVEL;players=2;activatedLevel=1;}
    if(x>scn.width/2-100&&x<scn.width/2+100&&y>450&&y<480){predictionActivationScene=BUILD_LEVEL;}
    if(x>scn.width/2-100&&x<scn.width/2+100&&y>500&&y<530){predictionActivationScene=SETINGS;}
    }

    void setupBuildLevel(HWND *hwnd){
    Scene &scn = scenes[activatedScene];
    scn.var.resize(0);
    scn.var.resize(7);
    scn.var[0]=scn.var[1]=scn.var[2]=scn.var[3]=scn.var[4]=scn.var[5]=scn.var[6]=0;
    scn.lastHeight=0;
    scn.lastWidth=0;
    //createExemplePlates();
    }
    void scriptBuildLevel(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[activatedScene];
    bool menu = scn.var[6];
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    int &x = scn.var[0],&y = scn.var[1];
    scn.draw(hdc);
    if(!menu){
    if(scn.var[2]==1){
    if(x>scn.width/2+270&&x<scn.width/2+330&&y>scn.height/2-250&&y<scn.height/2-210){activateScene(hwnd,MAIN_MENU);}
    if(x>scn.width/2+350&&x<scn.width/2+410&&y>scn.height/2-250&&y<scn.height/2-210){
            //game
            scn.var[6] = 1;
            scn.var[2] = 0;
            //createLevelMap(0,buildingLevelMap);activateScene(hwnd,LOAD_LEVEL);
    }
    if(x>scn.width/2+370&&x<scn.width/2+370+40&&y>scn.height/2-200&&y<scn.height/2-200+40){(++scn.var[3])%=4;}
    if(x>scn.width/2+370&&x<scn.width/2+370+40&&y>scn.height/2-150&&y<scn.height/2-150+40){(++scn.var[4])%=4;}
    }
    if(scn.var[2]==1){}
    exemplesPlates[1].type = BRICK_HALF_1_PLATE+scn.var[3];
    exemplesPlates[3].type = METAL_HALF_1_PLATE+scn.var[4];
    int i = 0,j=0;
    while(i<4){
        while(j<2){

          if(exemplesPlates[i*2+j].touch(x,y)){scn.var[5]=i*2+j;}

       j++; }
       j=0;
    i++;}
    i = 13,j=13;
    while(i>0){
        while(j>0){
            if(buildingLevelMap[i-1][j-1].touch(x,y)&&
            buildingLevelMap[i-1][j-1].type<BASE_PLATE
            ){
            buildingLevelMap[i-1][j-1].type = exemplesPlates[scn.var[5]].type;buildingLevelMap[i-1][j-1].redraw=true;}
            j--;
        }
        j=13;
        i--;
    }}else{


    int X = scn.width/2-95,Y = scn.height/2-45;
    if(scn.var[2]==1&&x>=0&&x<=scn.width&&y>=0&&y<=scn.height&&
    !(x>=X&&x<=X+190&&y>=Y&&y<=Y+90)&&
    !(x>scn.width/2+350&&x<scn.width/2+410&&y>scn.height/2-250&&y<scn.height/2-210)){scn.var[6] = 0;scn.var[2] = 0;}
    if(x>scn.width/2+350&&x<scn.width/2+410&&y>scn.height/2-250&&y<scn.height/2-210&&scn.var[2]==1){
            //game
            scn.var[2] = 0;
            scn.var[6] = 0;
            createLevelMap(0,buildingLevelMap);predictionActivationScene=LOAD_LEVEL;
            activatedLevel=0;
    }
    //script
    if(scn.var[2]==1){
    if(x>=X+10&&x<=X+60&&y>=Y+10&&y<=Y+40){players = 1;}
    if(x>=X+130&&x<=X+180&&y>=Y+10&&y<=Y+40){players = 2;}

    if(x>=X+10&&x<=X+60&&y>=Y+50&&y<=Y+80){levels[0].enemyType = 1;}
    if(x>=X+70&&x<=X+120&&y>=Y+50&&y<=Y+80){levels[0].enemyType = 2;}
    if(x>=X+130&&x<=X+180&&y>=Y+50&&y<=Y+80){levels[0].enemyType = 3;}

    }
    //script
    if(x>=X&&x<=X+190&&y>=Y&&y<=Y+90){scn.var[2]=0;}
    }
    scn.lastHeight = scn.height;
    scn.lastWidth = scn.width;
    }
    void drawBuildLevel(HDC *hdc){
    Scene &scn = scenes[activatedScene];
    if(scn.lastWidth!=scn.width||scn.lastHeight!=scn.height){

    setColor(hdc,0,0,0);
    Rectangle(*hdc,0,0,scn.width,scn.height);
    setColor(hdc,10,10,10);
    Rectangle(*hdc,scn.width/2-260,scn.height/2-260,scn.width/2+260,scn.height/2+260);
    setColor(hdc,50,50,50);
    Rectangle(*hdc,scn.width/2+260,scn.height/2-260,scn.width/2+260+160,scn.height/2+260);
    setColor(hdc,150,150,150);
    Rectangle(*hdc,scn.width/2+270,scn.height/2-250,scn.width/2+330,scn.height/2-210);
    Rectangle(*hdc,scn.width/2+350,scn.height/2-250,scn.width/2+410,scn.height/2-210);
    SetTextColor(*hdc,RGB(0,0,0));
    SetBkColor(*hdc,RGB(150,150,150));
    TextOutA(*hdc,scn.width/2+285,scn.height/2-237,"EXIT",5);
    TextOutA(*hdc,scn.width/2+365,scn.height/2-237,"PLAY",5);
    HDC hMemDC=CreateCompatibleDC(*hdc);
    SelectObject(hMemDC,images);
    BitBlt(*hdc,scn.width/2+370,scn.height/2-200,40,40,hMemDC,0,330,SRCCOPY);
    BitBlt(*hdc,scn.width/2+370,scn.height/2-150,40,40,hMemDC,0,330,SRCCOPY);
    DeleteDC(hMemDC);}

    int i = 0,j=0;
    while(i<4){
        while(j<2){
                if(i*2+j==scn.var[5]){setColor(hdc,255,255,0);Rectangle(*hdc,scn.width/2+270+j*50-5,
                50+scn.height/2-250+i*50-5,
                scn.width/2+270+j*50+45,
                50+scn.height/2-250+i*50+45
                );}else{
                setColor(hdc,50,50,50);Rectangle(*hdc,scn.width/2+270+j*50-5,
                50+scn.height/2-250+i*50-5,
                scn.width/2+270+j*50+45,
                50+scn.height/2-250+i*50+45
                );
                }
           exemplesPlates[i*2+j].draw(hdc,scn.width/2+270+j*50,50+scn.height/2-250+i*50);

       j++; }
       j=0;
    i++;}
    i=13;
    j=13;
    while(i>0){
        while(j>0){
        if(true){
         buildingLevelMap[i-1][j-1].redraw=false;
        buildingLevelMap[i-1][j-1].draw(hdc,scn.width/2-260+(i-1)*40,scn.height/2-260+(j-1)*40);}j--;}
        j=13;
    i--;
    }
    if(scn.var[6]!=0){
        int X = scn.width/2-95,Y = scn.height/2-45;
        setColor(hdc,50,50,50);
        //190x110
        Rectangle(*hdc,scn.width/2-95,scn.height/2-45,scn.width/2+95,scn.height/2+45);

        SetBkColor(*hdc,RGB(100,100,100));
        SetTextColor(*hdc,RGB(50,50,50));

        setColor(hdc,255,255,0);
        //Rectangle(*hdc,X+10+60*levels[0].enemyType,Y+10,X+70+60*levels[0].enemyType,Y+40);

        if(players==1){Rectangle(*hdc,X+5,Y+5,X+65,Y+45);}else{
        Rectangle(*hdc,X+125,Y+5,X+185,Y+45);
        }
        Rectangle(*hdc,
            X+10+60*(levels[0].enemyType-1)-5,
            Y+45,
            X+10+60*(levels[0].enemyType-1)+55,
            Y+85
            );

        setColor(hdc,100,100,100);
        Rectangle(*hdc,X+10,Y+10,X+60,Y+40);

        Rectangle(*hdc,X+130,Y+10,X+180,Y+40);
        TextOutA(*hdc,X+18,Y+18,"ONE",4);
        TextOutA(*hdc,X+138,Y+18,"TWO",4);


        Rectangle(*hdc,X+10,Y+50,X+60,Y+80);
        Rectangle(*hdc,X+70,Y+50,X+120,Y+80);
        Rectangle(*hdc,X+130,Y+50,X+180,Y+80);
        TextOutA(*hdc,X+13,Y+58,"EASY",5);
        TextOutA(*hdc,X+75,Y+58,"MED",4);
        TextOutA(*hdc,X+133,Y+58,"HARD",5);


    }
    }
    void buttonBuildLevel(int x,int y){
    Scene &scn = scenes[activatedScene];
    scn.var[0] = x;
    scn.var[1] = y;
    scn.var[2] = 1;
    }

    void setupLevelLoad(HWND *hwnd){
    Scene &scn = scenes[activatedScene];
    scn.var.resize(0);
    scn.var.resize(2);
    scn.var[0] = activatedLevel;
    scn.var[1] = 0;
    //int a;
    //cout<<"enter a number"<<endl;
    //cin>>a;
    //saveLevel(a);
    }
    void scriptLevelLoad(HWND *hwnd,HDC *hdc){

    music.play("resurses\\sounds\\startGame.wav");
    Scene &scn = scenes[activatedScene];
    scn.var.resize(2);
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    int &i = scn.var[1];
    if(i<200){scn.draw(hdc);}else{predictionActivationScene = GAME;}
    i+=10;
    }
    void drawLevelLoad(HDC *hdc){
    Scene &scn=  scenes[activatedScene];
    setColor(hdc,0,0,0);
    Rectangle(*hdc,0,0,scn.width,scn.height);
    string number = to_string(scn.var[0]);
    string text =activatedLevel==0?"CUSTOM STAGE" : "STAGE "+number;
    SetTextColor(*hdc,RGB(255,255,255));
    SetBkColor(*hdc,RGB(0,0,0));
    TextOutA(*hdc,scn.width/2-30,scn.var[1]+200,text.c_str(),activatedLevel==0?13:7+(scn.var[0]>=10?2:1
                                                                                     ));
    }
    void buttonLevelLoad(int x,int y){}

    void setupGameResults(HWND *hwnd){
    Scene &scn = scenes[activatedScene];

    scn.lastHeight = scn.lastWidth = 0;
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    scn.var.resize(11);
    scn.var[0] = 30;
    scn.var[1] = scn.var[2] = scn.var[3]= scn.var[4]= scn.var[5]= scn.var[6] = scn.var[7]= scn.var[8]= scn.var[9]= scn.var[10] =  0;
    }
    void scriptGameResults(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[GAME_RESULTS];
    scn.width = width(hwnd);
    scn.height = height(hwnd);

    int x = scn.var[8],y = scn.var[9];
    bool touch = scn.var[10];
    bool ended = scn.var[1] == killsInfo[0].lt&&scn.var[2]==killsInfo[0].st&&scn.var[3]==killsInfo[0].tt&&
    scn.var[4] == killsInfo[1].lt&&scn.var[5] == killsInfo[1].st && scn.var[6]==killsInfo[1].tt
    ;
    if(ended&&touch&&x>=scn.width/2-260&&x<=scn.width/2+260&&y>=scn.height/2-260&&y<=scn.height/2+260){
        if(activatedLevel==0){predictionActivationScene=BUILD_LEVEL;}else{
        predictionActivationScene = LOAD_LEVEL;activatedLevel++;if(activatedLevel==21){activatedLevel=1;}}
        scn.var[10] = 0;
    }
    bool endEdding = false;
    if(!ended){
        if(scn.var[1]<killsInfo[0].lt&&!endEdding){scn.var[1]++;endEdding=true;}
        if(scn.var[2]<killsInfo[0].st&&!endEdding){scn.var[2]++;endEdding=true;}
        if(scn.var[3]<killsInfo[0].tt&&!endEdding){scn.var[3]++;endEdding=true;}
        if(scn.var[4]<killsInfo[1].lt&&!endEdding){scn.var[4]++;endEdding=true;}
        if(scn.var[5]<killsInfo[1].st&&!endEdding){scn.var[5]++;endEdding=true;}
        if(scn.var[6]<killsInfo[1].tt&&!endEdding){scn.var[6]++;endEdding=true;}

    }
    if(!ended&&touch&&x>=scn.width/2-260&&x<=scn.width/2+260&&y>=scn.height/2-260&&y<=scn.height/2+260){
        scn.var[1]  = killsInfo[0].lt;
        scn.var[2]  = killsInfo[0].st;
        scn.var[3]  = killsInfo[0].tt;
        scn.var[4]  = killsInfo[1].lt;
        scn.var[5]  = killsInfo[1].st;
        scn.var[6]  = killsInfo[1].tt;

        scn.var[10] = 0;
    }

    scn.draw(hdc);
    delay(500);
    }
    void drawGameResults(HDC *hdc){
    Scene &scn = scenes[GAME_RESULTS];

    vector<int> &N = scn.var;

    int w = scn.width, h = scn.height;
    string n[6] = {to_string(N[1]),to_string(N[2]),to_string(N[3]),to_string(N[4]),to_string(N[5]),to_string(N[6])};
    int x = w/2-260,y = h/2-260;
    setColor(hdc,0,0,0);
    Rectangle(*hdc,0,0,w,h);
    setColor(hdc,10,10,10);
    Rectangle(*hdc,w/2-260,h/2-260,w/2+260,h/2+260);

    setColor(hdc,255,255,255);
    MoveToEx(*hdc,x+110,y+60,0);
    LineTo(*hdc,x+310+(players>1?100:0),y+60);
    LineTo(*hdc,x+310+(players>1?100:0),y+460);
    LineTo(*hdc,x+110,y+460);
    LineTo(*hdc,x+110,y+60);

    MoveToEx(*hdc,x+110,y+160,0);
    LineTo(*hdc,x+310+(players>1?100:0),y+160);
    MoveToEx(*hdc,x+110,y+260,0);
    LineTo(*hdc,x+310+(players>1?100:0),y+260);
    MoveToEx(*hdc,x+110,y+360,0);
    LineTo(*hdc,x+310+(players>1?100:0),y+360);
    MoveToEx(*hdc,x+210,y+60,0);
    LineTo(*hdc,x+210,y+460);
    MoveToEx(*hdc,x+310,y+60,0);
    LineTo(*hdc,x+310,y+460);

    SetTextColor(*hdc,RGB(255,255,255));
    SetBkColor(*hdc,RGB(10,10,10));

    TextOut(*hdc,x+250,y+210,n[0].c_str(),_tcslen(n[0].c_str()));
    TextOut(*hdc,x+250,y+310,n[1].c_str(),_tcslen(n[1].c_str()));
    TextOut(*hdc,x+250,y+410,n[2].c_str(),_tcslen(n[2].c_str()));

    tankTexture.draw(hdc,x+240,y+90,40,40,80,0);
    tankTexture.draw(hdc,x+140,y+190,40,40,40,320);
    tankTexture.draw(hdc,x+140,y+290,40,40,40,360);
    tankTexture.draw(hdc,x+140,y+390,40,40,40,400);

    if(players>1){
    TextOut(*hdc,x+350,y+210,n[3].c_str(),_tcslen(n[3].c_str()));
    TextOut(*hdc,x+350,y+310,n[4].c_str(),_tcslen(n[4].c_str()));
    TextOut(*hdc,x+350,y+410,n[5].c_str(),_tcslen(n[5].c_str()));
    tankTexture.draw(hdc,x+340,y+90,40,40,80,40);
    }
    }
    void buttonGameResults(int x,int y){
    Scene &scn = scenes[activatedScene];
    scn.var.resize(11);
    scn.var[8] = x;
    scn.var[9] = y;
    scn.var[10] = 1;
    }

    void setupGameOver(HWND *hwnd){
    Scene &scn = scenes[activatedScene];
    scn.var.resize(0);
    scn.var.resize(1);
    scn.var[0]=0;
    music.play("resurses\\sounds\\gameOver.wav");
    delay(100);
    music.play("resurses\\sounds\\gameOver.wav");

    delay(200);
    }
    void scriptGameOver(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[activatedScene];
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    int &i = scn.var[0];
    if(i!=200){scn.draw(hdc);}else{activateScene(hwnd,MAIN_MENU);}
    i+=10;
    }
    void drawGameOver(HDC *hdc){
        Scene &scn = scenes[activatedScene];
        int &i = scn.var[0];
        setColor(hdc,0,0,0);
        Rectangle(*hdc,0,0,scn.width,scn.height);


        HDC hMemDC=CreateCompatibleDC(*hdc);
        SelectObject(hMemDC,images);
        BitBlt(*hdc,scn.width/2-250,i-80,500,300,hMemDC,500,30,SRCCOPY);
        DeleteDC(hMemDC);

    }
    void buttonGameOver(int x,int y){}

    void setupGame(HWND *hwnd){
    Scene &scn = scenes[activatedScene];
    scn.var.resize(0);
    scn.var.resize(4);
    scn.var[0]=scn.var[1]=scn.var[2]=scn.var[3]=0;
    scn.lastWidth=0;
    scn.lastHeight=0;

    setup();

    }
    void scriptGame(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[GAME];
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    int x = scn.var[1],y = scn.var[2];
    scn.draw(hdc);

    scn.lastWidth = scn.width;
    scn.lastHeight = scn.height;

    loop(hwnd,hdc);
    if(x>scn.width/2+270&&x<scn.width/2+330&&y>scn.height/2-250&&y<scn.height/2-210){activateScene(hwnd,MAIN_MENU);}
    if(x>scn.width/2+350&&x<scn.width/2+410&&y>scn.height/2-250&&y<scn.height/2-210&&scn.var[3]==1){
            scn.var[3]=0;scn.var[0] = (scn.var[0]==0?1:0);  }


    }
    void drawGame(HDC *hdc){
    Scene &scn = scenes[GAME];

    setColor(hdc,0,0,0);
    Rectangle(*hdc,0,0,scn.width,scn.height);
    setColor(hdc,10,10,10);
    Rectangle(*hdc,scn.width/2-260,scn.height/2-260,scn.width/2+260,scn.height/2+260);
    setColor(hdc,50,50,50);
    Rectangle(*hdc,scn.width/2+260,scn.height/2-260,scn.width/2+260+160,scn.height/2+260);
    setColor(hdc,150,150,150);
    Rectangle(*hdc,scn.width/2+270,scn.height/2-250,scn.width/2+330,scn.height/2-210);
    Rectangle(*hdc,scn.width/2+350,scn.height/2-250,scn.width/2+410,scn.height/2-210);
    SetTextColor(*hdc,RGB(0,0,0));
    SetBkColor(*hdc,RGB(150,150,150));
    TextOutA(*hdc,scn.width/2+285,scn.height/2-237,"EXIT",5);
    setColor(hdc,150,150,150);
    Rectangle(*hdc,scn.width/2+350,scn.height/2-250,scn.width/2+410,scn.height/2-210);
    TextOutA(*hdc,scn.width/2+355,scn.height/2-237,scn.var[0]==0?"PAUSE":" PLAY",scn.var[0]==0?6:6);

    }
    void buttonGame(int x,int y){
    Scene &scn = scenes[activatedScene];
    scn.var[1] = x;
    scn.var[2] = y;
    scn.var[3] = 1;
    }

    void setupSetings(HWND *hwnd){
    Scene &scn = scenes[SETINGS];
    scn.var.resize(5);
    scn.var[0] = scn.var[1]=  scn.var[2] = 0;

    }
    void scriptSetings(HWND *hwnd,HDC *hdc){

    Scene &scn = scenes[SETINGS];
    int x = scn.var[0],y = scn.var[1];
    scn.width = width(hwnd);
    scn.height = height(hwnd);
    int w = scn.width,h = scn.height;
    if(scn.var[2]==1){scn.var[2]=0;
    if(x>=w/2+190&&x<=w/2+250&&y>=h/-250&&y<=h/2-210){
    predictionActivationScene = MAIN_MENU;}
    if(x>=w/2-200&&x<=w/2-200+25&&y>=h/2-215&&y<=h/2-215+25){setings.music = !setings.music;setings.save();}
    }
    if(GetAsyncKeyState(39)&&setings.delay<1000){setings.delay+=25;setings.save();}
    if(GetAsyncKeyState(37)&&setings.delay>0){setings.delay-=25;setings.save();}
    scn.draw(hdc);
    }
    void drawSetings(HDC *hdc){
    Scene &scn = scenes[SETINGS];
    int w = scn.width,h = scn.height;
    setColor(hdc,10,10,10);
    Rectangle(*hdc,0,0,scn.width,scn.height);
    setColor(hdc,0,0,0);
    Rectangle(*hdc,scn.width/2-260,scn.height/2-260,scn.width/2+260,scn.height/2+260);
    SetTextColor(*hdc,RGB(0,0,0));
    SetBkColor(*hdc,RGB(150,150,150));
    setColor(hdc,150,150,150);
    Rectangle(*hdc,scn.width/2+190,scn.height/2-250,scn.width/2+250,scn.height/2-210);
    TextOutA(*hdc,scn.width/2+205,scn.height/2-237,"EXIT",5);
    SetTextColor(*hdc,RGB(255,255,255));
    SetBkColor(*hdc,RGB(0,0,0));
    TextOut(*hdc,w/2-250,h/2-210,"SOUND",6);
    TextOut(*hdc,w/2-250,h/2-180,"DELAY",6);
    string delay = to_string(setings.delay);
    TextOut(*hdc,w/2-180,h/2-180,delay.c_str(),_tcslen(delay.c_str()));
    HDC dc = CreateCompatibleDC(*hdc);
    SelectObject(dc,images);

    BitBlt(*hdc,w/2-200,h/2-215,30,25,dc,160,370+(setings.music?0:25),SRCCOPY);
    DeleteDC(dc);
    }
    void buttonSetings(int x,int y){
    Scene &scn = scenes[SETINGS];
    scn.var[0] = x;
    scn.var[1]  = y;
    scn.var[2] = 1;
    }
    //methods for scenes

      Level gameLevel;

    //functions
    void brickConstractor(){
     int i = 26,j=26;
     while(i>0){
        while(j>0){
            Cell &c = gameLevel.map[i-1][j-1];
            c.body[0]=c.body[1]=c.body[2]=c.body[3]=1;
            j--;
        }
        i--;j=26;
     }
     }
    void setColor(HDC *hdc,int r,int g,int b){
    SetDCPenColor(*hdc,RGB(r,g,b));
    SetDCBrushColor(*hdc,RGB(r,g,b));
    }
    void createAnimations(){
    animations[MAIN_MENU].script = animationMainMenu;
    animations[LOAD_LEVEL].script = animationLevelLoad;
    animations[GAME_OVER].script = animationGame;
    animations[GAME].script = animationGame;
    animations[BUILD_LEVEL].script = animationCreateLevel;
    animations[GAME_RESULTS].script = animationGameResults;
    }
    void createScenes(){
    scenes[MAIN_MENU].setup = setupMainMenu;
    scenes[MAIN_MENU].script = scriptMainMenu;
    scenes[MAIN_MENU].draw   = drawMainMenu;
    scenes[MAIN_MENU].button = buttonMainMenu;
    scenes[MAIN_MENU].anim = &(animations[MAIN_MENU]);

    scenes[LOAD_LEVEL].setup = setupLevelLoad;
    scenes[LOAD_LEVEL].script = scriptLevelLoad;
    scenes[LOAD_LEVEL].draw = drawLevelLoad;
    scenes[LOAD_LEVEL].button = buttonLevelLoad;
    scenes[LOAD_LEVEL].anim = &(animations[LOAD_LEVEL]);

    scenes[BUILD_LEVEL].setup = setupBuildLevel;
    scenes[BUILD_LEVEL].script = scriptBuildLevel;
    scenes[BUILD_LEVEL].draw = drawBuildLevel;
    scenes[BUILD_LEVEL].button = buttonBuildLevel;
    scenes[BUILD_LEVEL].anim = &(animations[BUILD_LEVEL]);

    scenes[GAME_RESULTS].setup = setupGameResults;
    scenes[GAME_RESULTS].script = scriptGameResults;
    scenes[GAME_RESULTS].draw = drawGameResults;
    scenes[GAME_RESULTS].button = buttonGameResults;
    scenes[GAME_RESULTS].anim = &(animations[GAME_RESULTS]);

    scenes[GAME_OVER].setup = setupGameOver;
    scenes[GAME_OVER].script = scriptGameOver;
    scenes[GAME_OVER].draw = drawGameOver;
    scenes[GAME_OVER].button = buttonGameOver;
    scenes[GAME_OVER].anim = &(animations[GAME_OVER]);


    scenes[GAME].setup = setupGame;
    scenes[GAME].script = scriptGame;
    scenes[GAME].draw = drawGame;
    scenes[GAME].button = buttonGame;
    scenes[GAME].anim = &(animations[GAME]);

    scenes[SETINGS].setup = setupSetings;
    scenes[SETINGS].script = scriptSetings;
    scenes[SETINGS].draw = drawSetings;
    scenes[SETINGS].button = buttonSetings;
    }
    void activateScene(HWND*hwnd,int scene){
    if(scene!=LOAD_LEVEL){
    lastScene = activatedScene;}
    activatedScene = scene;
    scenes[activatedScene].setup(hwnd);
    }
    void createExemplePlates(){
    exemplesPlates[0].type = BRICK_PLATE;
    exemplesPlates[1].type = BRICK_HALF_1_PLATE;
    exemplesPlates[2].type = METAL_PLATE;
    exemplesPlates[3].type = METAL_HALF_1_PLATE;
    exemplesPlates[4].type = WATER_PLATE;
    exemplesPlates[5].type = ROAD_PLATE;
    exemplesPlates[6].type = TREES_PLATE;
    exemplesPlates[7].type = ISE_PLATE;
    int i=13,j=13;
    while(i>0){
        while(j>0){buildingLevelMap[i-1][j-1].type = ROAD_PLATE;j--;}
        j=13;
        i--;}
    InputMapPlate (&a)[13][13] = buildingLevelMap;
    a[0][0].type = a[12][0].type =a[6][0].type= SPECIAL_ROAD_PLATE;
    a[6][12].type = BASE_PLATE;
    a[6][11].type = SPECIAL_BRICK_3_PLATE;
    a[5][12].type = SPECIAL_BRICK_1_PLATE;
    a[7][12].type = SPECIAL_BRICK_2_PLATE;
    a[5][11].type = SPECIAL_BRICK_4_PLATE;
    a[7][11].type = SPECIAL_BRICK_5_PLATE;
    a[4][12].type = SPECIAL_ROAD_PLATE;
    a[8][12].type = SPECIAL_ROAD_PLATE;
    //buildingLevelMap[12][0].type = BRICK_PLATE;
    }
    void createLevelMap(int level,InputMapPlate (&plates)[13][13]){
    Cell (&lvl)[26][26] = levels[level].map;
    int i = 13,j=13;
    brickConstractor();

    while(i>0){
        while(j>0){
           //  brickConstractor();
            switch (plates[i-1][j-1].type){
            case ROAD_PLATE:
            case SPECIAL_ROAD_PLATE:

            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = ROAD;

            break;
            case BRICK_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = BRICK;
            break;
            case SPECIAL_BRICK_1_PLATE:
            case BRICK_HALF_2_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = BRICK;
            lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case SPECIAL_BRICK_2_PLATE:
            case BRICK_HALF_4_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = ROAD;
            lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = BRICK;
            break;

            case BRICK_HALF_1_PLATE:
            lvl[i*2-1][j*2-1].type =lvl[i*2-2][j*2-1].type = ROAD;
            lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-2].type = BRICK;
            break;
            case SPECIAL_BRICK_3_PLATE:
            case BRICK_HALF_3_PLATE:
            lvl[i*2-1][j*2-1].type =lvl[i*2-2][j*2-1].type = BRICK;
            lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case SPECIAL_BRICK_4_PLATE:
            lvl[i*2-1][j*2-1].type = BRICK;
            lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case SPECIAL_BRICK_5_PLATE:
            lvl[i*2-2][j*2-1].type = BRICK;
            lvl[i*2-1][j*2-1].type =lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case METAL_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = METAL;
            break;
            case METAL_HALF_3_PLATE:
            lvl[i*2-1][j*2-1].type =lvl[i*2-2][j*2-1].type = METAL;
            lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case METAL_HALF_2_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = METAL;
            lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = ROAD;
            break;
            case METAL_HALF_1_PLATE:
            lvl[i*2-1][j*2-1].type =lvl[i*2-2][j*2-1].type = ROAD;
            lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-2].type = METAL;
            break;
            case METAL_HALF_4_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = ROAD;
            lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = METAL;
            break;
            case TREES_PLATE:
            lvl[i*2-1][j*2-1].type = lvl[i*2-1][j*2-2].type = lvl[i*2-2][j*2-1].type = lvl[i*2-2][j*2-2].type = TREE;
            break;
            case WATER_PLATE:
            lvl[i*2-1][j*2-1].type = WATER4;
            lvl[i*2-1][j*2-2].type = WATER2;
            lvl[i*2-2][j*2-1].type = WATER3;
            lvl[i*2-2][j*2-2].type = WATER1;
            break;
            case ISE_PLATE:
            lvl[i*2-1][j*2-1].type = ISE4;
            lvl[i*2-1][j*2-2].type = ISE2;
            lvl[i*2-2][j*2-1].type = ISE3;
            lvl[i*2-2][j*2-2].type = ISE1;
            break;
            case BASE_PLATE:
            lvl[i*2-1][j*2-1].type = BASE4;
            lvl[i*2-1][j*2-2].type = BASE2;
            lvl[i*2-2][j*2-1].type = BASE3;
            lvl[i*2-2][j*2-2].type = BASE1;
            break;
            }
       j--; }
       i--;j=13;
    }

    }


    void saveLevel(int n){
    Level &lvl = levels[0];
    string path = "resurses\\levels\\level"+to_string(n)+".txt";

    ofstream file;

    file.open(path);
    if(!file.is_open()){
        cout<<"file is not open!"<<endl;
    }else{
    cout<<"file is open!\n start to save!"<<endl;

    file<<lvl.enemyType<<"\n";

    int i = 0,j = 0;

    while(i<26){
        while(j<26){
            file<<lvl.map[j][i].type<< " ";
            cout<<lvl.map[j][i].type<<" ";
            j++;
        }
        i++;
        j=0;
        file<<"\n";
        cout<<"\n";
    }

    }
    cout<<path<<endl;
    file.close();

    }

    void loadLevel(int n){
    Level &lvl = levels[n];
    string path = "resurses\\levels\\level"+to_string(n)+".txt";
    ifstream file;
    file.open(path);
    //cout<<"file is : "<<path<<endl;
    if(!file.is_open()){
       // cout<<"error! file is not open!"<<endl;

    }else{
   // cout<<"file is open! start to reeding"<<endl;
    int i = 0,j = 0;
    file>>lvl.enemyType;
    while(!file.eof()&&i<26){
        int a;
        file>>a;
        lvl.map[j][i].type = a;
        //cout<<a<<" ";
        j++;
        if(j==26){j=0;i++;}
    }

    }

    }
    //functions
    //game
    bool enemiesFreeze = false;
    int addBonusCount = 0;
    int needToSpawn = 3;

    class Detonation;
    class Shot;
    class Bonus;
    class Event;
    class Tank;
    class Gamer;
    class Enemy;
    class BonusPlate;
    int addDetonation(int x,int y,int type,int typeTank,int side);
    int addShot(int x,int y,int type,int side,int typeTank);

    void setBaseBrick(Level &lvl,int type){

    Cell (&m)[26][26] = lvl.map;
    vector<int> a = {1,1,1,1};
    m[11][25].type = m[14][25].type = m[11][24].type = m[14][24].type = m[11][23].type = m[14][23].type=m[12][23].type = m[13][23].type=type;
    m[11][25].body = m[14][25].body = m[11][24].body = m[14][24].body = m[11][23].body = m[14][23].body=m[12][23].body = m[13][23].body=a;
    }
    void bonusSetup(Bonus &b);
    void bonusScript(Bonus &b);
    void bonusEnd(Bonus &b);
    void getBonusFunction(BonusPlate &bp);
    void activateBonus(int type,int tankType);
    void createKillsInfo();
    void createMatrix();
    void createTanksInfo();
    void createShotsInfo();

    int setTank(Tank &tank,int tankType);

    void detonateTankByCordsAndType(int x,int y,int type);

    struct Kill{
    short killer;
    short killed;
    };
    struct EnemySpawnInfo{
    short type;
    bool spawned = false;
    };
    struct DetonationTank{
    int x;
    int y;
    int type ;
    };
    vector<DetonationTank> tankDetonations;
    vector<Kill> kills;
    void addTankDetonation(int x,int y,int type){
        tankDetonations.resize(tankDetonations.size()+1);
        tankDetonations[tankDetonations.size()-1].x = x;
        tankDetonations[tankDetonations.size()-1].y = y;
        tankDetonations[tankDetonations.size()-1].type = type;
    }
    struct ShotInfo{
    int x;
    int y;
    int tankType;
    int side;
    };
    struct TankInfo{
    int x;
    int y;
    int type;
    bool spawning;
    };
    void addKill(int killer,int killed){
    kills.resize(kills.size()+1);
    kills[kills.size()-1].killed = killed;
    kills[kills.size()-1].killer = killer;
    }
    bool spawnEnemyFunction();
    class Intelect;
    void intelectFunction(Enemy &enm,HDC *hdc);
    class EnemySpawn{
    public:
    vector<short> tt;
    vector<EnemySpawnInfo> esi;
    void create(){
    esi.resize(0);
    Level &lvl = levels[activatedLevel];
    int et = lvl.enemyType;
    int n = et==1?10:et==2?15:21;
    esi.resize(n);
    tt.resize(n);


   if(et==1){tt= {1,1,1,1,1,1,1,1,0,0};}
    if(et==2){tt={1,0,2,1,0,2,1,0,2,1,0,2,1,0,2};}
    if(et==3){tt={1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2};}

    while(n>0){
        int nt  = tt[n-1];
        esi[n-1].type = (nt==0)?LT_TANK:(nt==1)?ST_TANK:TT_TANK;

    n--; }
    }
    bool (*spawn)() = spawnEnemyFunction;
    };
    class ShotsInfo{
    public:
    vector<ShotInfo> shots;
    void (*create)() = createShotsInfo;
    bool findShotByCords(int x,int y,int tankType){
    int i = shots.size();
    while(i>0){
        ShotInfo &s = shots[i-1];
        bool inX = (s.side%2!=0)?(x==s.x):(x>=s.x-1&&x<=s.x+1);
        bool inY = (s.side%2==0)?(y==s.y):(y>=s.y-1&&y<=s.y+1);
        if(s.tankType!=tankType&&inX&&inY){return true;}
        i--;
    }
    return false;
    }
    };
    class TanksInfo{
    public:
    vector<TankInfo> tanks;
    void (*create)() = createTanksInfo;
    TankInfo lat;
    bool findTankByCords(int x,int y,int type,bool spflag){
    int i = tanks.size();
    while(i>0){
        TankInfo &t = tanks[i-1];
        int X = t.x,Y= t.y;
        //cout<<x<<" "<<X<<" "<<y<<" "<<Y<<" "<<type<<" "<<t.type<<endl;
        if(x>=X-1&&x<=X+1&&y>=Y-1&&y<=Y+1&&t.type!=type){lat.x = X;lat.y = Y;lat.type = t.type;return true;}
        i--;
    }
    return false;
    }
    int getTankTypeByCords(int x,int y,int type){
    if(lat.x>=x-1&&lat.x<=x+1&&lat.y>=y-1&&lat.y<=y+1&&lat.type!=type){return lat.type;}
    int i = tanks.size();
    while(i>0){
        TankInfo &t = tanks[i-1];
        int X = t.x,Y= t.y;
        if(X>=x-1&&X<=x+1&&Y>=y-1&&Y<=x+1&&t.type!=type){lat.x = X;lat.y = Y;lat.type = t.type;return t.type;}
        i--;
    }
    }
    };

    struct PlateInfo{
    public:
    bool tank = false;
    short tankType;
    short road=0;
    short water = false;
    };
    class Matrix{
    public:
    PlateInfo m[25][25];

    TanksInfo tanks;
    ShotsInfo shots;
    void (*create)() = createMatrix;

    };
    Matrix matrix;
    EnemySpawn enemySpawn;
    void copyLevel(Level &fromlvl,Level &tolvl){
    int i = 26,j = 26;
    while(i>0){
        while(j>0){
        tolvl.map[i-1][j-1].type = fromlvl.map[i-1][j-1].type;
        j--;}
        i--;
        j=26;
    }
    }
    int GameDrawDelay = 0;
    class TankSpawnAnimation{
    public:
    int x;
    int y;
    int progres = 0;
    int maxProgres = 4;
    void script(){
    progres = (progres<maxProgres)?progres+1:maxProgres;
    }
    void draw(HDC *hdc){
    Scene &scn = scenes[activatedScene];
    int w = scn.width,h  = scn.height;
    eventAndBonusTexture.draw(hdc,w/2-240+(x-1)*20,h/2-240+(y-1)*20,40,40,40*(progres),80);
    }
    };
    class Tank{
    public:
    TankSpawnAnimation span;
    int armoryTime = 80;
    short x =0;
    short y=0;
    int id;
    short type;
    bool spawning = true;
    bool detonated = false;
    short rotationSide=1;
    short shotDelay;
    short shotDelayCount=0;
    short hp = 0;
    bool onIse = false;
    void shotDelayTaker(){
    if(shotDelayCount>0){shotDelayCount--;}

    }
    void iseMove(){
        if(armoryTime>0){armoryTime--;}
        span.x = x;
        span.y = y;
        span.script();

        if(span.progres==span.maxProgres){spawning=false;}

        if(!detonated&&!spawning){
        if(onIse){
        onIse = false;
    int sx = x,sy = y;

        switch(rotationSide){
        case 1:
        y--;
        break;
        case 2:
        x++;
        break;
        case 3:
        y++;
        break;
        case 4:
        x--;
        break;
        }

    if(x<0){x=0;}
    if(y<0){y=0;}
    if(x>24){x=24;}
    if(y>24){y=24;}
    PlateInfo &p = matrix.m[x][y];
    if(p.road==1||p.water||matrix.tanks.findTankByCords(x,y,type<LT_TANK?type:id,true)){x=sx;y=sy;}
    }}
    }
    void det(){
        if((type<LT_TANK?armoryTime==0:true)){
        if(type==TT_TANK){hp+= hp>=0?-1:0;}

        if(!detonated&&(type==TT_TANK?hp<0:true)&&(type<LT_TANK?type==LVL1_1_TANK||type==LVL1_2_TANK:true)){
    detonated=true;
    addDetonation(x,y,TANK_DETONATION,type,0);}

    if(type>=LVL2_1_TANK&&type<=LVL4_2_TANK){type-=2;}
        }
    }
    void shot(){
        if(!detonated&&!spawning){
        if(shotDelayCount==0){
                music.play("resurses\\sounds\\shot.wav");
    addShot(x,y,GAMER_SHOT,rotationSide,type<LT_TANK?type:id);shotDelayCount=shotDelay;
    delay(120);
    }}
    }
    void rot(int side){
        if(!detonated&&!spawning){
    rotationSide = side;}
    }
    void mov(int side){
    if(!detonated&&!spawning){
    int sx = x,sy = y;
    if(side!=rotationSide){rot(side);}else{
        switch(side){
        case 1:
        y--;
        break;
        case 2:
        x++;
        break;
        case 3:
        y++;
        break;
        case 4:
        x--;
        break;
        }
    }
    if(x<0){x=0;}
    if(y<0){y=0;}
    if(x>24){x=24;}
    if(y>24){y=24;}
    PlateInfo &p = matrix.m[x][y];
    if(p.road==1||p.water||matrix.tanks.findTankByCords(x,y,type<LT_TANK?type:id,true)){x=sx;y=sy;}
    if(p.road==2){onIse = true;}

    }
    }
    void draw(HDC *hdc){

       if(spawning){
        span.draw(hdc);
       }

    if(!detonated&&!spawning){
    Scene &scn = scenes[activatedScene];
    int sy = 40*(type-hp),sx = 40*(rotationSide-1),X = scn.width/2-240+(x-1)*20,Y = scn.height/2-240+(y-1)*20;
    tankTexture.draw(hdc,X,Y,40,40,sx,sy);
    if(armoryTime>0&&type<LT_TANK){
        eventAndBonusTexture.draw(hdc,X,Y,40,40,40*(armoryTime%2),280);
    }
    }}
    };
    class Detonation{
    public:
    int type;
    int typeTank;
    int side;
    int x;
    int y;
    bool was = false;
    void script(){
    switch(type){
    case GAMER_SHOT_DETONATION:
    case ENEMY_SHOT_DETONATION:
    if(matrix.m[x][y].road==1&&!was){

       if(x>=0&&y>=0){ gameLevel.map[x][y].destroy(side,typeTank);}
        if(y>=0&&x<=24){gameLevel.map[x+1][y].destroy(side,typeTank);}
       if(x>=0){ gameLevel.map[x][y+1].destroy(side,typeTank);}
       if(y<=24&&x<=24) gameLevel.map[x+1][y+1].destroy(side,typeTank);

    }
    break;
    case TANK_DETONATION:
    addTankDetonation( x, y, typeTank);
    break;
    }
    was = true;
    }
    void draw(HDC *hdc){
        Scene &scn = scenes[activatedScene];
    if(!was){
        switch(type){
        case GAMER_SHOT_DETONATION:
        case ENEMY_SHOT_DETONATION:
        eventAndBonusTexture.draw(hdc,scn.width/2-240+(x-1)*20,scn.height/2-240+(y-1)*20,40,40,0,40);
        break;
        case TANK_DETONATION:
        eventAndBonusTexture.draw(hdc,scn.width/2-240+(x-1)*20,scn.height/2-240+(y-1)*20,40,40,40,40);
        break;
    }}

    }
    };
    class Shot{
    public:
        int x;
        int y;
        short type;
        short typeTank;
        short side;
        bool was;
        void setup(){}
        void script(){
        int sx = x,sy = y;
        if(!was&&type!=VOID_SHOT){
        switch (side){
        case 1:
        y--;
        break;
        case 2:
        x++;
        break;
        case 3:
        y++;
        break;
        case 4:
        x--;
        break;
        }
        if(x<0){was=true;addDetonation(x,y,type,typeTank,side);}
        if(y<0){was=true;addDetonation(x,y,type,typeTank,side);}
        if(x>24){was=true;addDetonation(x,y,type,typeTank,side);}
        if(y>24){was=true;addDetonation(x,y,type,typeTank,side);}

        //if(!end){matrix.shots.create();}
        if(matrix.m[x][y].road==1||matrix.tanks.findTankByCords(x,y,typeTank,true)){was=true;addDetonation(x,y,type,typeTank,side);detonateTankByCordsAndType(x,y,typeTank);music.play("resurses\\sounds\\det.wav");delay(120);}
        if(matrix.shots.findShotByCords(x,y,typeTank)){type=VOID_SHOT;addDetonation(x,y,type,typeTank,side);x=sx;y=sy;music.play("resurses\\sounds\\det.wav");delay(120);}


        }}
        void draw(HDC *hdc){

            Scene &scn = scenes[activatedScene];
            int sx = (side-1)*40,X = scn.width/2-240+(x-1)*20 ,Y = scn.height/2-240+(y-1)*20;
            if(!was){
            eventAndBonusTexture.draw(hdc,X,Y,40,40,sx,0);}
        }
    };
    class Bonus{
    public:
        bool setuped = false;
        vector<int> var;
        short type;
        bool was = false;
        void (*setup)(Bonus &b) = bonusSetup;
        void (*script)(Bonus &b) = bonusScript;
        void (*end)(Bonus &b) = bonusEnd;
    };
    class BonusPlate{
    public:
    short x;
    short y;
    bool got = false;
    short type;
    short time = 200;
    short delay = 1;
    void draw(HDC *hdc){
    time--;
    if(time==0){got=true;}
    Scene &scn = scenes[activatedScene];
    int w = scn.width,h = scn.height;
    if(time<100){delay--;}
    if(delay==-1){delay=time<50?3:time<100?7:1;}
    if(!got&&delay!=0){
    eventAndBonusTexture.draw(hdc,w/2-240+(x-1)*20,h/2-240+(y-1)*20,40,40,(type%4)*40,200+40*(type/4));}
    }
    void (*get)(BonusPlate &bp) = getBonusFunction;
    };
    class Event{
    public:
        short type;
        void setup(){}
        void script(){}
    };
    class Gamer{
    public:
    short number;
    Tank tank;
    };
    class Enemy{
    public:
    short id = rand();
    bool died = false;
    short type;
    Tank tank;
    short intelectUpdate = 3;
    void (*intelect)(Enemy &enm,HDC *hdc) = intelectFunction;
    };


    vector<Detonation> detonations;
    vector<Shot> shots;
    vector<Gamer> gamers;
    vector<Enemy> enemies;
    vector<Bonus> bonuses;
    vector<Event> events;
    vector<BonusPlate> bonusPLates;



    bool checkSpawnPoint(int x,int y){
    if(
    !matrix.tanks.findTankByCords(x,y,-1,false)){return true;}
    return false;

    }


    bool spawnEnemyFunction(){
    EnemySpawn &es = enemySpawn;
    int i = 0;
    int n = -1;
    int lastLength = enemies.size();
    while(i<es.esi.size()){

        if(!es.esi[i].spawned&&i!=es.esi.size()){n = i;i = es.esi.size();}


        i++;
    }
    bool good = false;
    enemies.resize(enemies.size()+1);
    Enemy &en = enemies[enemies.size()-1];

    if(n!=-1){
    setTank(enemies[enemies.size()-1].tank,es.esi[n].type);
    }
    if(n==-1){enemies.resize(enemies.size()-1);}
    if(lastLength!=enemies.size()){
        es.esi[n].spawned=true;
        srand(rand());
        enemies[enemies.size()-1].id = rand();
        enemies[enemies.size()-1].tank.id = enemies[i-1].id;
        while(enemies[enemies.size()-1].tank.id>=0&&enemies[enemies.size()-1].tank.id<=TT_TANK){
            enemies[enemies.size()-1].tank.id = rand();
        }
        return true;
    }
    return false;
    }
    int addBonusPlate(int x,int y,int type){

    int i = bonusPLates.size();

    while(i>0){
        if(bonusPLates[i-1].got){
            bonusPLates[i-1].got=false;
            bonusPLates[i-1].x = x;
            bonusPLates[i-1].y = y;
            bonusPLates[i-1].type = type;
            bonusPLates[i-1].time = 200;
            bonusPLates[i-1].delay = 1;
            return 0;
        }
        i--;
    }
    bonusPLates.resize(bonusPLates.size()+1);

    bonusPLates[bonusPLates.size()-1].x=x;
    bonusPLates[bonusPLates.size()-1].y=y;
    bonusPLates[bonusPLates.size()-1].type=type;
    }
    int addBonus(int type){

        int i = bonuses.size();

        while(i>0){
            if(bonuses[i-1].was){bonuses[i-1].was = false;bonuses[i-1].type=type;bonuses[i-1].setuped=false;return 0;}
            i--;
        }
        bonuses.resize(bonuses.size()+1);
        bonuses[bonuses.size()-1].type = type;
    }
    int addDetonation(int x,int y,int type,int typeTank,int side){
    int i = detonations.size();
        while(i>0){
            if(detonations[i-1].was){
            detonations[i-1].typeTank = typeTank;
            detonations[i-1].side = side;
            detonations[i-1].was=false;detonations[i-1].x=x;
            detonations[i-1].y=y;
            detonations[i-1].type=type;return 0;}
        i--; }
        detonations.resize(detonations.size()+1);
        detonations[detonations.size()-1].type = type;
        detonations[detonations.size()-1].x = x;
        detonations[detonations.size()-1].y = y;
        detonations[detonations.size()-1].typeTank = typeTank;
        detonations[detonations.size()-1].side = side;
        return 0;
    }
    int addShot(int x,int y,int type,int side,int typeTank){
    int i = shots.size();
        while(i>0){
            if(shots[i-1].was||shots[i-1].type==VOID_SHOT){
                shots[i-1].typeTank=typeTank;
            shots[i-1].was=false;shots[i-1].x=x;
            shots[i-1].y=y;shots[i-1].type=type;
            shots[i-1].side=side;return 0;}
        i--; }
        shots.resize(shots.size()+1);
        shots[shots.size()-1].type = type;
        shots[shots.size()-1].x = x;
        shots[shots.size()-1].y = y;
        shots[shots.size()-1].side = side;
        shots[shots.size()-1].typeTank = typeTank;
        return 0;
    }
    int setTank(Tank &tank,int tankType){

    if(tankType>=LT_TANK){
        tank.armoryTime = 0;
        tank.type = tankType;
        tank.rotationSide = 3;
        tank.shotDelay = 10;
        tank.detonated = false;
        tank.hp = tankType==TT_TANK?2:0;
        tank.x = 0;
        tank.y = 0;
        if(checkSpawnPoint(0,0)){tank.x = 0;return 0;}
        if(checkSpawnPoint(12,0)){tank.x = 12;return 0;}
        if(checkSpawnPoint(24,0)){tank.x = 24;return 0;}
        enemies.resize(enemies.size()-1);
        return 0;

    }else{
    tank.armoryTime = 80;
    tank.type = tankType;
    tank.shotDelay = 4+3-(tankType/2);
    tank.rotationSide = 1;
    tank.detonated = false;
    tank.hp = 0;
    tank.y = 24;
    tank.x = 12+(tankType%2==0?-3:3);
    }
    return 0;
    }
    void deleteGamer(int number){
    if(number==2){
        gamers.resize(1);
    }else{
        if(gamers.size()==2){
    gamers[0].number = gamers[1].number;
    gamers[0].tank.type = gamers[1].tank.type;
    gamers[0].tank.shotDelay = gamers[1].tank.shotDelay;
    gamers[0].tank.shotDelayCount = gamers[1].tank.shotDelayCount;
    gamers[0].tank.rotationSide = gamers[1].tank.rotationSide;
    gamers.resize(1);
        }else{gamers.resize(0);}
    }
    }
    void setGamer(int number,int tankType){
    gamers[number-1].number = number;
    setTank(gamers[number-1].tank,tankType);
    }
    void deleteEnemy(int id){

    }
    void setEnemy(int id,int tankType){

    }

    void detonateTankByCordsAndType(int x,int y,int type){
    matrix.create();
    int i = gamers.size();
    while(i>0){
        Tank &t = gamers[i-1].tank;
        if(x>=t.x-1&&x<=t.x+1&&y>=t.y-1&&y<=t.y+1&&t.type!=type&&!t.detonated){t.det();
        if(t.detonated){addKill(type,t.type);}
        }

        i--;
    }
    i = enemies.size();
    while(i>0){
        Tank &t = enemies[i-1].tank;
        if(x>=t.x-1&&x<=t.x+1&&y>=t.y-1&&y<=t.y+1&&t.id!=type&&!t.detonated&&!enemies[i-1].died){t.det();if(type!=-1){addBonusCount++;}
        if(t.detonated){addKill(type,t.type);needToSpawn++;enemies[i-1].died=true;}}
        i--;
    }

    matrix.create();
    }
    void createShotsInfo(){
    int i = shots.size();
    matrix.shots.shots.resize(0);
    while(i>0){
       if(!shots[i-1].was||shots[i-1].type==VOID_SHOT){ matrix.shots.shots.resize(matrix.shots.shots.size()+1);
        matrix.shots.shots[matrix.shots.shots.size()-1].tankType = shots[i-1].typeTank;
        matrix.shots.shots[matrix.shots.shots.size()-1].x = shots[i-1].x;
        matrix.shots.shots[matrix.shots.shots.size()-1].y = shots[i-1].y;
        matrix.shots.shots[matrix.shots.shots.size()-1].side = shots[i-1].side;
        }
        i--;
    }
    }
    void createTanksInfo(){
    TanksInfo &t = matrix.tanks;
    t.tanks.resize(0);
    int i = gamers.size();
    while(i>0){
        if(!gamers[i-1].tank.detonated){
        t.tanks.resize(t.tanks.size()+1);
        t.tanks[t.tanks.size()-1].x = gamers[i-1].tank.x;
        t.tanks[t.tanks.size()-1].y = gamers[i-1].tank.y;
        t.tanks[t.tanks.size()-1].type = gamers[i-1].tank.type;
        t.tanks[t.tanks.size()-1].spawning = gamers[i-1].tank.spawning;
        }
        i--;
    }
     i = enemies.size();
    while(i>0){
        if(!enemies[i-1].tank.detonated){
        t.tanks.resize(t.tanks.size()+1);
        t.tanks[t.tanks.size()-1].x = enemies[i-1].tank.x;
        t.tanks[t.tanks.size()-1].y = enemies[i-1].tank.y;
        t.tanks[t.tanks.size()-1].type = enemies[i-1].tank.id;
        t.tanks[t.tanks.size()-1].spawning = gamers[i-1].tank.spawning;
        }
        i--;
    }
    }
    void createMatrix(){
    Level &lvl = gameLevel;
    PlateInfo (&m)[25][25] = matrix.m;
    int i = 25,j = 25;
    while(i>0){
        while(j>0){


            int a = lvl.map[i-1][j-1].type, b = lvl.map[i][j-1].type, c = lvl.map[i-1][j].type, d = lvl.map[i][j].type;
            bool unroad = a==BRICK||a==METAL||b==BRICK||b==METAL||c==BRICK||c==METAL||d==BRICK||d==METAL
           // ||a>=WATER1&&a<=WATER4||b>=WATER1&&b<=WATER4||c>=WATER1&&c<=WATER4||d>=WATER1&&d<=WATER4||
            ||a>=BASE1&&a<=BASE4||b>=BASE1&&b<=BASE4||c>=BASE1&&c<=BASE4||d>=BASE1&&d<=BASE4;

            m[i-1][j-1].road = unroad?1:0;
            bool onIse = a>=ISE1&&a<=ISE4&&b>=ISE1&&b<=ISE4&&c>=ISE1&&c<=ISE4&&d>=ISE1&&d<=ISE4;
            bool water = a>=WATER1&&a<=WATER4||b>=WATER1&&b<=WATER4||c>=WATER1&&c<=WATER4||d>=WATER1&&d<=WATER4;
            if(onIse){m[i-1][j-1].road=2;}
            //if(water){m[i-1][j-1].water = true;}
            m[i-1][j-1].water = water;
       j--; }
       j=25;
       i--;
    }


    matrix.tanks.create();
    matrix.shots.create();
    }

    bool spawnTank(){
    matrix.create();
    return enemySpawn.spawn();
    }

    int calcUnGotBonuses(){
    int i = bonusPLates.size(),n=0;
    while(i>0){
        if(!bonusPLates[i-1].got){n++;}
        i--;
    }

    return n;
    }

    bool findBonusByCords(int x,int y){
    int i = bonusPLates.size();
    while(i>0){
        int X = bonusPLates[i-1].x,Y = bonusPLates[i-1].y;
        if(x>=X-1&&x<=X+1&&y>=Y-1&&y<=Y+1&&!bonusPLates[i-1].got){return true;}
        i--;
    }
    return false;
    }

    void addBonuses(){
    int n = addBonusCount;

    while(n>0){
        int a = rand()%2,b = rand()%2;
        int x = 6+a*12,y = 6+b*12,t = (rand()%2)*4+2*(rand()%2)+(rand()%2);
        bool good = true;
        if(players==1&&(t==GAMER2_ARMOR_BONUS||t==GAMER2_LVL_BONUS)){good = false;}
        if(good&&calcUnGotBonuses()<1&&!findBonusByCords(x,y)&&!matrix.tanks.findTankByCords(x,y,-1,true)){
            if(rand()%2==0){
            addBonusPlate(x,y,t);}
            addBonusCount--;
        }
        n--;
    }

    }

    void activateBonus(int type,int tankType){

    int bt;
    if(players>1){
        if(type==0||type==1){bt = tankType%2;}
        if(type==2||type==3){bt = 2+(tankType%2);}
        if(type>3){bt=type;}
    }else{
    bt=type;
    }
    addBonus(bt);
    }

    void spawnNewEnemy(){

    int i = needToSpawn;
    while(i>0){


        if(spawnTank()){needToSpawn--;}


        i--;
    }

    }

    int calcUnDiedEnemies(){
    int i = enemies.size(),n  = 0;
    while(i>0){
        if(!enemies[i-1].died){n++;}
        i--;
    }
    return n;
    }
    class GameOver{
    public :
    int time =  15;
    bool is = false;
    bool endded = false;
    void start(){
    is = true;
    }
    bool end(){return endded;}
    void script(){
    if(!endded&&is){time--;}
    if(time == 0){endded=true;}
    }
    void draw(HDC *hdc){
    if(!endded&&is){
    //setColor(hdc,255,0,0);
    //Rectangle(*hdc,1000,1000,300,300);
    Scene &scn=  scenes[activatedScene];
    int w = scn.width, h = scn.height;
    eventAndBonusTexture.draw(hdc,w/2-80,h/2-100+10*time,160,60,0,120);
    }
    }
    };
    class Win{
    public:
    int time = 60;
    bool started = false;
    void script(){
        if(started){

    if(time>0){time--;}else{
        predictionActivationScene = GAME_RESULTS;
        createKillsInfo();
    }
    }}
    bool check(){

    if(calcUnDiedEnemies()==0){started = true;return true;}
    return false;
    }
    };
    GameOver gameOver;
    Win win;
    void bonusScript(Bonus &b){
        if(!b.was){
    if(!b.setuped){b.setup(b);b.setuped=true;}
    //script
    switch(b.type){
    case TIME_BONUS:

    b.var[0]--;
    if(b.var[0]==0){b.end(b);}else{
        enemiesFreeze=true;
    }

    break;
    case BASE_BONUS:

        b.var[0]--;
        if(b.var[0]==0){b.end(b);}else{
            if(b.var[0]<50){b.var[1]--;}
            if(b.var[1]==-1){b.var[1]=b.var[0]<20?3:b.var[0]<50?7:1;}
            setBaseBrick(gameLevel,b.var[1]==0?BRICK:METAL);
        }

    break;
    }
    }
    }
    void bonusSetup(Bonus &b){
    switch(b.type){

        case RESPAWN_BONUS:
        if(players>1&&gamers[1].tank.detonated){gamers[1].tank.detonated=false;setTank(gamers[1].tank,LVL1_2_TANK);}
        if(gamers[0].tank.detonated){gamers[0].tank.detonated = false;setTank(gamers[0].tank,LVL1_1_TANK);}
        b.end(b);
        break;
        case GAMER1_LVL_BONUS:
            if(gamers[0].tank.type<6){gamers[0].tank.type+=2;}
            b.end(b);
        break;
        case GAMER2_LVL_BONUS:
            if(gamers[1].tank.type<6){gamers[1].tank.type+=2;}
            b.end(b);
        break;
        case ENEMIES_BONUS:
        {


            int i = enemies.size();
            if(i>0){music.play("resurses\\sounds\\det.wav");delay(100);}
            while(i>0){

             if(!enemies[i-1].tank.detonated){
                detonateTankByCordsAndType(enemies[i-1].tank.x,enemies[i-1].tank.y,-1);
                detonateTankByCordsAndType(enemies[i-1].tank.x,enemies[i-1].tank.y,-1);
                detonateTankByCordsAndType(enemies[i-1].tank.x,enemies[i-1].tank.y,-1);
             }
               i--;

            }
            b.end(b);}
        break;
        case GAMER1_ARMOR_BONUS:
        gamers[0].tank.armoryTime=200;
        b.end(b);
        break;
        case GAMER2_ARMOR_BONUS:
        gamers[1].tank.armoryTime=200;
        b.end(b);
        break;
        case TIME_BONUS:
        b.var.resize(1);
        b.var[0] = 100;
        break;
        case BASE_BONUS:
        {
            b.var.resize(2);
            b.var[0] = 100;
            b.var[1] = 1;
            setBaseBrick(gameLevel,METAL);
        }
        break;
        }
    }
    void bonusEnd(Bonus &b){
    b.was = true;
        switch(b.type){
        case TIME_BONUS:
        enemiesFreeze = false;
        break;
        case BASE_BONUS:
        setBaseBrick(gameLevel,BRICK);
        break;
        }

    }
    void getBonusFunction(BonusPlate &bp){
    if(!bp.got){
        int x = bp.x,y = bp.y;
        Tank &t1 = gamers[0].tank;
        int X = t1.x,Y = t1.y;
        if(X>=x-1&&X<=x+1&&Y>=y-1&&Y<=y+1&&!t1.detonated){
        bp.got=true;activateBonus(bp.type,t1.type);
        }
        if(players>1&&!bp.got){
            Tank &t2 = gamers[1].tank;
            X = t2.x;
            Y = t2.y;
            if(X>=x-1&&X<=x+1&&Y>=y-1&&Y<=y+1&&!t2.detonated){
            bp.got=true;activateBonus(bp.type,t2.type);
            }
        }

    }

    }

    void createKillsInfo(){
    killsInfo[0].lt = killsInfo[1].lt = killsInfo[0].st = killsInfo[1].st = killsInfo[0].tt = killsInfo[1].tt = 0;

    int i = kills.size();
    while(i>0){

        Kill &k = kills[i-1];

            if(k.killed>=LT_TANK&&k.killer<LT_TANK){
            killsInfo[k.killer%2].lt += k.killed==LT_TANK?1:0;
            killsInfo[k.killer%2].st += k.killed==ST_TANK?1:0;
            killsInfo[k.killer%2].tt += k.killed==TT_TANK?1:0;
            }


        i--;
    }

    }
    void createGamers(int n){

    bool a = activatedLevel>1;
    if(!a){gamers.resize(0);}
    gamers.resize(n);

    int t1 = a?gamers[0].tank.type:LVL1_1_TANK;

    setTank(gamers[0].tank,t1);
    if(gamers.size()>1){
            int t2 = a?gamers[1].tank.type:LVL1_2_TANK;
            setTank(gamers[1].tank,t2);}

    }
    void reset(bool fool){
    if(fool){gamers.resize(0);}
    kills.resize(0);
    enemies.resize(0);
    shots.resize(0);
    detonations.resize(0);
    bonuses.resize(0);
    bonusPLates.resize(0);
    events.resize(0);
    needToSpawn=3;
    gameOver.endded = false;
    gameOver.is = false;
    gameOver.time = 30;
    win.time = 60;
    win.started = false;
    addBonusCount=0;
    }
    void setup(){

    reset(false);
    createGamers(players);

    copyLevel(levels[activatedLevel],gameLevel);

    brickConstractor();
    enemySpawn.create();

    }
    int keyBoardUpdateCount = 0;
    bool checkGameOver(){
        Level &lvl = gameLevel;
    int i = 26,j = 26;
    int n=0;
    while(i>0){
        while(j>0){
            if(lvl.map[i-1][j-1].type>=BASE1&&lvl.map[i-1][j-1].type<=BASE4){n++;}
            j--;
        }
        i--;
        j=26;
    }
    bool g = gamers[0].tank.detonated&&(players>1?gamers[1].tank.detonated:true);
    if(n==4&&!g){return false;}
    return true;
    }
    void draw(HDC *hdc){
    int i;
    Level &lvl = gameLevel;
    lvl.drawBottom(hdc);

    i = shots.size();
    while(i>0){
        shots[i-1].draw(hdc);
        i--;
    }
    i = gamers.size();
    while(i>0){
        gamers[i-1].tank.draw(hdc);
        i--;
    }
    i = enemies.size();

    while(i>0){

        enemies[i-1].tank.draw(hdc);

        i--;
    }

    i = detonations.size();
    while(i>0){
        detonations[i-1].draw(hdc);
        i--;
    }
    i = bonusPLates.size();
    while(i>0){
        bonusPLates[i-1].draw(hdc);
        i--;
    }
    lvl.drawTrees(hdc);
    gameOver.draw(hdc);
    }
    void keyBoard(){
    bool p = scenes[activatedScene].var[0]||gameOver.is;
    if(GetAsyncKeyState(87)&&!p){gamers[0].tank.mov(1);}
    if(GetAsyncKeyState(83)&&!p){gamers[0].tank.mov(3);}
    if(GetAsyncKeyState(68)&&!p){gamers[0].tank.mov(2);}
    if(GetAsyncKeyState(65)&&!p){gamers[0].tank.mov(4);}
    if(GetAsyncKeyState(32)&&!p){gamers[0].tank.shot();}
    if(gamers.size()>1){
    if(GetAsyncKeyState(38)&&!p){gamers[1].tank.mov(1);}
    if(GetAsyncKeyState(40)&&!p){gamers[1].tank.mov(3);}
    if(GetAsyncKeyState(39)&&!p){gamers[1].tank.mov(2);}
    if(GetAsyncKeyState(37)&&!p){gamers[1].tank.mov(4);}
    if(GetAsyncKeyState(190)&&!p){gamers[1].tank.shot();}
    }

    }
    void loop(HWND *hwnd,HDC *hdc){
    Scene &scn = scenes[activatedScene];
    Level &lvl = gameLevel;
    int i;
    //cdd.start();
    if(!scn.var[0]&&!gameOver.is){
        //script
        createMatrix();

        i = gamers.size();
        while(i>0){
            gamers[i-1].tank.iseMove();
            gamers[i-1].tank.shotDelayTaker();
            i--;
        }
        i = enemies.size();
        while(i>0){
            enemies[i-1].tank.onIse = false;
            enemies[i-1].tank.iseMove();
            enemies[i-1].tank.shotDelayTaker();
            if(!enemiesFreeze){enemies[i-1].intelect(enemies[i-1],hdc);}
            i--;
        }
        i = detonations.size();
       while(i>0){
        detonations[i-1].script();
        i--;
       }
        i = shots.size();
        while(i>0){
           shots[i-1].script();
       i--; }
       i = shots.size();
       while(i>0){
        if(shots[i-1].type==VOID_SHOT){shots[i-1].was=true;shots[i-1].type=shots[i-1].typeTank%2;}
       i--;}
        i  = bonusPLates.size();
        while(i>0){
            bonusPLates[i-1].get(bonusPLates[i-1]);
            i--;
        }
        i = bonuses.size();
        while(i>0){
            bonuses[i-1].script(bonuses[i-1]);
            i--;
        }
        spawnNewEnemy();
        addBonuses();
    }


    if(keyBoardUpdateCount++>KEY_BOARD_UPDATE){keyBoardUpdateCount=0;
    keyBoard();}
    gameOver.script();
    if(checkGameOver()){
        gameOver.start();}
        if(gameOver.end()){
        predictionActivationScene=GAME_OVER;}
    win.check();
    win.script();
    if(activatedScene==GAME){
    draw(hdc);}

    //enemies[0].intelect(enemies[0],hdc);

    //GameDrawDelay =  cdd.end()*5;
    }


    class Target{
    public:
    int x;
    int y;
    int way;
    };



    class Tmap{
    public:
    Target *target;

    float temp[25][25];

    void create(Target &tg){

    target = &tg;
    matrix.create();
    int i=0,j = 0;

    while(i<25){

        while(j<25){

            if(matrix.m[i][j].road==1||matrix.m[i][j].water){temp[i][j] = 1000.0;}else{

              float x = abs(i-tg.x),y = abs(j-tg.y);

              temp[i][j] = sqrt(x*x+y*y);
            }

            j++;
        }

        j=0;
        i++;
    }

    }
    };



    class Intelect{
    public:
    Enemy *enemy;
    vector<Target> targets;
    Target *target;
    int calcWallsCount(){

    Tank &e = (*enemy).tank;
    Target &tg = *target;

    int side = toTargetSide();
    int px=0,py=0;
    if(side==1){py=-1;}
    if(side==2){px=1;}
    if(side==3){py=1;}
    if(side==4){px=-1;}
    int x=e.x,y=e.y,count=0;
    matrix.create();
    while(!xys(tg.x,tg.y,x,y)&&x>=0&&x<=24&&y>=0&&y<=24){
        if(matrix.m[x][y].road==1){count++;}

        x+=px;
        y+=py;
    }


    return count;
    }
    int toTargetSide(){
    Target &tg =  *target;
    Enemy &e = *enemy;

    if(abs(tg.x-e.tank.x)>abs(tg.y-e.tank.y)){

       if(e.tank.x>tg.x){return 4;}else{return 2;}

    }else{

    if(e.tank.y>tg.y){return 1;}else{return 3;}

    }
    }
    bool xypms(int x1,int y1, int x2,int y2){

    return (
    x1>=x2-1&&x1<=x2+1||y1>=y2-1&&y1<=y2+1
    );
    }
    bool xys(int x1,int y1, int x2,int y2){

    return (
    x1>=x2-1&&x1<=x2+1&&y1>=y2-1&&y1<=y2+1
    );
    }
    void findNearestTarget(){

    float w1 = targets[0].way,w2 = targets[1].way,w3 = players>1?targets[2].way:100.0;
    if(w2<=w1&&w2<=w3){target = &targets[1];}
    if(w3<=w1&&w3<=w2){target = &targets[2];}
    if(w1<=w2&&w1<=w3){target = &targets[0];}

    }
    int canShot(){

    createTargets();
    findNearestTarget();

    Target &tg = *target;
    Enemy &enm = *enemy;
    int x1 = tg.x,x2=  enm.tank.x,y1 = tg.y,y2 = enm.tank.y;
    if(!xypms(x1,y1,x2,y2)){return 0;}
    int a = calcWallsCount();

    if(a<5&&tg.way<8){
    return toTargetSide();
    }
    return 0;
    }
    float calcWayToTarget(float x1,float y1,float x2,float y2){

    float x = abs(x1-x2),y = abs(y1-y2);

    float w = sqrt(x*x+y*y);
    return w;

    }
    void createTargets(){
    Enemy &e = *enemy;
    if(players>1){targets.resize(3);}else{targets.resize(2);}
    targets[0].x = 12;
    targets[0].y = 24;
    targets[0].way = calcWayToTarget(e.tank.x,e.tank.y,targets[0].x,targets[0].y);
    targets[1].x = gamers[0].tank.x;
    targets[1].y = gamers[0].tank.y;
    targets[1].way = gamers[0].tank.detonated?100.0:calcWayToTarget(e.tank.x,e.tank.y,targets[1].x,targets[1].y);
    if(players>1){
        targets[2].x = gamers[1].tank.x;
        targets[2].y = gamers[1].tank.y;
        targets[2].way = gamers[1].tank.detonated?100.0:calcWayToTarget(e.tank.x,e.tank.y,targets[2].x,targets[2].y);
    }

    }

    void ride(int side){
    Enemy &enm = *enemy;
    //if(canShot()){enm.tank.shot();}
    if(enm.tank.rotationSide!=side){enm.tank.rot(side);}else{
    int x = enm.tank.x,y = enm.tank.y;
    int tt = enm.tank.type;
    enm.tank.type = enm.id;
    enm.tank.mov(side);
    enm.tank.type = tt;
    if(enm.tank.x==x&&enm.tank.y==y){enm.tank.shot();}
    }
    //enm.tank.shot();
    }
    void random(){
        createTargets();
    Enemy &enm = *enemy;
    int a =(rand()%2)*8+ (rand()%2)*4+(rand()%2)*2+(rand()%2);

    if(a<4){ride(a+1);}
    if(a>=4&&a<=12){ride(enm.tank.rotationSide);}


    }
    void smart(bool area,HDC *hdc){
    if(!area){
    createTargets();
    float w1 = targets[0].way,w2 = targets[1].way,w3 = players>1?targets[2].way:100.0;
    if(w2<=w1&&w2<=w3){target = &targets[1];}
    if(w3<=w1&&w3<=w2){target = &targets[2];}
    if(w1<=w2&&w1<=w3){target = &targets[0];}

    }
    Enemy &enm = *enemy;
    Target &tg = *target;
    Tmap tmap;
    tmap.create(tg);
    int w1,w2,w3,w4,w = tg.way;
    w1=w2=w3=w4=2000.0;
    if(enm.tank.x>0){w4=tmap.temp[enm.tank.x-1][enm.tank.y];}
    if(enm.tank.y>0){w1=tmap.temp[enm.tank.x][enm.tank.y-1];}
    w2=tmap.temp[enm.tank.x+1][enm.tank.y];
    w3=tmap.temp[enm.tank.x][enm.tank.y+1];
    int side = 0;
    if(w1<w&&enm.tank.rotationSide!=3){side=1;}
    if(w2<w&&enm.tank.rotationSide!=4){side=2;}
    if(w3<w&&enm.tank.rotationSide!=1){side=3;}
    if(w4<w&&enm.tank.rotationSide!=2){side=4;}

    if(side!=0){ride(side);}else{random();}

    }
    void area(HDC *hdc){
    createTargets();
    bool tgc = false;
    if(targets[2].way<6.0){target = &targets[2];tgc = true;}
    if(targets[1].way<6.0){target = &targets[1];tgc = true;}
    if(targets[0].way<6.0){target = &targets[0];tgc = true;}

    if(tgc){smart(true,hdc);}else{random();}

    }
    void think(Enemy &enm,HDC *hdc){
    enemy = &enm;

    int et = enm.tank.type,lt = levels[activatedLevel].enemyType;
    int side = canShot();
    if(side!=0){enm.tank.rot(side);enm.tank.shot();}else{
    if(lt==EASY){random();}
    if(lt==MEDIUM){
        if(et==ST_TANK){area(hdc);}else{random();}
    }
    if(lt==HARD){
        if(et==ST_TANK){smart(false,hdc);}else{area(hdc);}
    }

    }}
    };
    Intelect intelect;
    void intelectFunction(Enemy &enm,HDC *hdc){
    if(enm.intelectUpdate--==0){
        if(!enm.tank.detonated){
    enm.intelectUpdate = enm.tank.type<LT_TANK?3:2;
    intelect.think(enm,hdc);}}
    }
    //game


void drawLoadingProgress(HWND *hwnd,HDC *hdc,int progres,string msg){



int w = width(hwnd),h = height(hwnd);

SelectObject(*hdc,GetStockObject(DC_BRUSH));
SelectObject(*hdc,GetStockObject(DC_PEN));

setColor(hdc,0,0,0);

Rectangle(*hdc,0,0,5000,5000);
SetBkColor(*hdc,RGB(0,0,0));
SetTextColor(*hdc,RGB(255,255,255));

TextOut(*hdc,w/2,h/2,(to_string(progres)+"%").c_str(),_tcslen((to_string(progres)+"%").c_str()));
TextOut(*hdc,w/2-30,h/2+20,msg.c_str(),_tcslen(msg.c_str()));
TextOut(*hdc,w/2,h/2+40," ",2);

}
void loadLevels(){
int i = 1;

while(i<21){
    loadLevel(i);
    i++;

}
}
void LOADING(HWND *hwnd,HDC *hdc){

    drawLoadingProgress(hwnd,hdc,0,"STARTING LOADING...");

    HDC tdc = CreateCompatibleDC(*hdc);
    HBITMAP bmp = CreateCompatibleBitmap(*hdc,3000,3000);
    SelectObject(tdc,bmp);
    delay(1500);
    drawLoadingProgress(hwnd,hdc,20,"LOADING SCENES...");
    delay(1500);
    createAnimations();
    createScenes();
    createExemplePlates();
    activateScene(hwnd,MAIN_MENU);
    drawLoadingProgress(hwnd,hdc,40,"LOADING TEXTURES...");
    //delay(500);
     tankTexture.create(&tdc,280,330,0,0,0);
     eventAndBonusTexture.create(&tdc,0,370,0,0,0);
     drawLoadingProgress(hwnd,hdc,60,"LOADING LEVELS...");
     loadLevels();
    delay(2000);
     drawLoadingProgress(hwnd,hdc,80,"ENDING...");
     delay(1000);
activateScene(hwnd,MAIN_MENU);
drawLoadingProgress(hwnd,hdc,99,"THE END...");
delay(1000);
setings.load();
drawLoadingProgress(hwnd,hdc,100,"STARTING PROGRAM...");
delay(1500);
}

void Main(HWND *hwnd){
PAINTSTRUCT ps;
HDC hdcMain = BeginPaint(*hwnd,&ps);
HDC hdc = CreateCompatibleDC(hdcMain);
HBITMAP bmp = CreateCompatibleBitmap(hdcMain,3000,1000);

int lastWidth = width(hwnd);
int lastHeight = height(hwnd);


LOADING(hwnd,&hdcMain);
MUSIC = true;
//saveLevel(0);

while(true){
    if(lastWidth!=width(hwnd)||lastHeight!=height(hwnd)){
        lastHeight=height(hwnd);
        lastWidth=width(hwnd);
        bmp = CreateCompatibleBitmap(hdcMain,width(hwnd),height(hwnd));
    }

    SelectObject(hdc,bmp);
    SelectObject(hdc,GetStockObject(DC_BRUSH));
    SelectObject(hdc,GetStockObject(DC_PEN));
    scenes[activatedScene].script(hwnd,&hdc);
    BitBlt(hdcMain,0,0,width(hwnd),height(hwnd),hdc,0,0,SRCCOPY);
    if(predictionActivationScene!=-1){
        activateScene(hwnd,predictionActivationScene);
        predictionActivationScene=-1;
    }
    if(activatedScene==GAME){this_thread::sleep_for(chrono::milliseconds(setings.delay));

    }else{
this_thread::sleep_for(chrono::milliseconds(50));}
}
EndPaint(*hwnd,&ps);
}


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CREATE:
        images = (HBITMAP)LoadImage(NULL,"resurses\\images\\buttons.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
        break;
        case WM_PAINT:

        break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        case WM_LBUTTONDOWN:
        if(MUSIC){
        scenes[activatedScene].button(LOWORD(lParam),HIWORD(lParam));
        if(activatedScene!=GAME||activatedScene!=LOAD_LEVEL){music.play("resurses\\sounds\\click.wav");}
        }
        break;
        case WM_MOUSEMOVE:
        if(activatedScene==BUILD_LEVEL&&scenes[activatedScene].var[2]==1){
        scenes[activatedScene].button(LOWORD(lParam),HIWORD(lParam));}
        break;
        case WM_LBUTTONUP:
            //scenes[activatedScene].button(LOWORD(lParam),HIWORD(lParam));
            if(activatedScene==BUILD_LEVEL){
                scenes[activatedScene].var[2] = 0;
            }
        break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}







