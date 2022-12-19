#include<iostream>
#include<stdlib.h>
#include<graphics.h>
using namespace std;

class shape{
    int xco,yco,rad,colour;
    char dir;
    int x,y;

    public:
    void draw(){        
        cout<<"Enter radius : ";
        cin>>rad;

        cout<<"Enter Co-Ordinate : ";
        cin>>xco>>yco;

        cout<<"Enter colour : ";
        cin>>colour;

        initwindow(1500 , 1080);

        setfillstyle(1 , colour);
        circle(xco,yco,rad);
        floodfill(xco+1 , yco+1 ,WHITE);

        getch();
        closegraph();

    }

    void move(){
        int j=0;
        cout<<"Enter co-ordinate : ";
        cin>>x>>y;
        initwindow(1500 , 1080);
        for(int i=0 ; i<=x || j<=y ; i=i+50){
            j=j+50;
            cleardevice();
            setfillstyle(1 , colour);
            circle(xco+i,yco+j,rad);
            floodfill(xco+1+i , yco+1+j ,WHITE);
            
            delay(500);
        }
        getch();
        closegraph();
     
    }
};

class complexshape:protected shape{
    int a,b,c,d,color;
    char dir;

    public:

    complexshape(){
        cout<<"Enter Co-ordinate : ";
        cin>>a>>b;
        cout<<endl<<"Enter box colour : ";
        cin>>color;

    }
    void create(){
        initwindow(1500,1080);
    }

    void draw(int i=0 , int  j=0 ){
        
        


        setfillstyle(1 , color);
        rectangle(a+i,b+j,a+200+i,b+120+j);
        floodfill(a+1+i, b+1+j,15);

        setfillstyle(7 , 6);
        rectangle(a+20+i,b+20+j,a+70+i,b+70+j);
        floodfill(a+20+1+i , b+20+1+j ,WHITE);

        setfillstyle(7 , 6);
        rectangle(a+20+100+i,b+20+j,a+70+100+i,b+70+j);
        floodfill(a+20+100+1+i , b+20+1+j ,WHITE);

        setfillstyle(5 , 8);
        circle(a+50+i , b+150+j , 30);
        floodfill(a+50+1+i , b+150+1+j ,WHITE);
        circle(a+50+100+i , b+150 +j, 30);
        floodfill(a+50+100+1+i , b+150+1+j ,WHITE);

        line(a+200+i,b+60+j , a+270+i , b+60+j);

        setfillstyle(1 , color);
        rectangle(a+270+i,b+j,a+200+270+i,b+120+j);
        floodfill(a+1+270 +i, b+1+j ,15);

        setfillstyle(7 , 6);
        rectangle(a+270+20+i,b+20+j,a+270+70+i,b+70+j);
        floodfill(a+270+20+1+i , b+20+1+j ,WHITE);

        rectangle(a+270+20+100+i,b+20+j,a+270+100+70+i,b+70+j);
        floodfill(a+270+20+100+1 +i, b+20+1+j ,WHITE);

        setfillstyle(5 , 8);
        circle(a+270+50+i , b+150+j , 30 );
        floodfill(a+270+50+1+i , b+150+1+j ,WHITE);
        circle(a+270+50 +100+i , b+150+j , 30 );
        floodfill(a+270+50 +100+1 +i, b+150+1+j ,WHITE);
        delay(300);


    }
    void hold(){
        getch();
        closegraph();

    }

    void move(int i=0 , int j=0){
        for(i = 0 ; i<700 ; i=i+50){            
            
            cleardevice();
            draw(i,j);
        }
    }

    

};

class simpleshape:protected shape{

};

class box:protected simpleshape{
    int a,b,c,d,colour;
    char dir;


    public:

    void draw(){
        
        cout<<"Enter Co-ordinate : ";
        cin>>a>>b>>c>>d;

        cout<<"Enter colour : ";
        cin>>colour;

        initwindow(1500,1080);
        setfillstyle(SOLID_FILL , colour);
        rectangle(a,b,c,d);
        floodfill(a+1 , b+1 ,WHITE);
        getch();
        closegraph();

    }

    void move(){
        cout<<"Enter direction : "<<endl<<"L - Left\nR - Right\nU - Up\nD - Down\n";
        cout<<endl;
        cin>>dir;

        switch(dir){
            case 'R':
                initwindow(1500,1080);
                setfillstyle(SOLID_FILL , colour);

                for(int i=0 ; i<900 ; i=i+50){
                    cleardevice();
                    rectangle(a+i,b,c+i,d);
                    floodfill(a+1+i , b+1 ,WHITE);
                    delay(300);
            
                }
                getch();
                closegraph();
            break;

            case 'L':
                initwindow(1500,1080);
                setfillstyle(SOLID_FILL , colour);
                for(int i=0 ; i<900 ; i=i+50){
                 cleardevice();
                rectangle(a-i,b,c-i,d);
                floodfill(a+1-i , b+1 ,WHITE);
                delay(300);
                }
                getch();
                closegraph();
            break;

            case 'U':
                initwindow(1500,1080);
                setfillstyle(SOLID_FILL , colour);
                for(int i=0 ; i<900 ; i=i+50){
                 cleardevice();
                rectangle(a,b-i,c,d-i);
                floodfill(a+1 , b+1-i ,WHITE);
                delay(300);
                }
                getch();
                closegraph();
            break;

            case 'D':
                initwindow(1500,1080);
                setfillstyle(SOLID_FILL , colour);
                for(int i=0 ; i<900 ; i=i+50){
                 cleardevice();

                rectangle(a,b+i,c,d+i);
                floodfill(a+1 , b+1+i ,WHITE);
                delay(300);
                }
                getch();
                closegraph();
            break;
        }        
    }
};

class tent:protected simpleshape{

    int a,b,c,d,y;
    float x;
    char dir;
    public:
    

    void draw(){
        
        cout<<"Enter Co-ordinate : ";
        cin>>a>>b>>c>>d;

        x=1.7322*0.5*(c-a);
        y=x;

        initwindow(1500,800);
     //   setfillstyle(SOLID_FILL , GREEN);
        line(a,b,c,d);
        line(a,b+(c-a),c,d+(c-a));
        line(a,b,a,b+(c-a));
        line(c,d,c,d+(c-a));
       // floodfill(a+1 , b+1 , WHITE);
        line(a,b,a+((c-a)/2),d-y);
        line(c,d,a+((c-a)/2),d-y);
        
        getch();
        closegraph();

    }

    void move(){

        cout<<"Enter direction : "<<endl<<"L - Left\nR - Right\nU - Up\nD - Down\n";
        cout<<endl;
        cin>>dir;

        switch(dir){
            case 'R':
                initwindow(1500,800);
                for(int i=0 ; i<900 ; i=i+50){
                    cleardevice();
                    line(a+i,b,c+i,d);
                    line(a+i,b+(c-a),c+i,d+(c-a));
                    line(a+i,b,a+i,b+(c-a));
                    line(c+i,d,c+i,d+(c-a));
                    line(a+i,b,a+((c-a)/2)+i,d-y);
                    line(c+i,d,a+((c-a)/2)+i,d-y);                
                    delay(300);

                }
                getch();
                closegraph();
            break;

            case 'L':
                initwindow(1500,800);
                for(int i=0 ; i<900 ; i=i+50){
                    cleardevice();
                    line(a-i,b,c-i,d);
                    line(a-i,b+(c-a),c-i,d+(c-a));
                    line(a-i,b,a-i,b+(c-a));
                    line(c-i,d,c-i,d+(c-a));
                    line(a-i,b,a+((c-a)/2)-i,d-y);
                    line(c-i,d,a+((c-a)/2)-i,d-y);                
                    delay(300);

                }
                getch();
                closegraph();
            break;

            case 'U':
                initwindow(1500,800);
                for(int i=0 ; i<900 ; i=i+50){
                    cleardevice();
                    line(a,b-i,c,d-i);
                    line(a,b+(c-a)-i,c,d+(c-a)-i);
                    line(a,b-i,a,b+(c-a)-i);
                    line(c,d-i,c,d+(c-a)-i);
                    line(a,b-i,a+((c-a)/2),d-y-i);
                    line(c,d-i,a+((c-a)/2),d-y-i);                
                    delay(300);

                }
                getch();
                closegraph();
            break;

            case 'D':
                initwindow(1500,800);
                for(int i=0 ; i<900 ; i=i+50){
                    cleardevice();
                    line(a,b+i,c,d+i);
                    line(a,b+(c-a)+i,c,d+(c-a)+i);
                    line(a,b+i,a,b+(c-a)+i);
                    line(c,d+i,c,d+(c-a)+i);
                    line(a,b+i,a+((c-a)/2),d-y+i);
                    line(c,d+i,a+((c-a)/2),d-y+i);                
                    delay(300);

                }
                getch();
                closegraph();
            break;
        }
    }    
};

int main(){
    int choice,i;

    cout<<"1) Shape"<<endl<<"2) Box"<<endl<<"3) Tent"<<endl<<"4) Complex shape"<<endl;

    for(i=0 ; i==i ; i++){
    cout<<"Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            shape ob;
            ob.draw();
            ob.move();
        break;

        case 2:
            box b;
            b.draw();
            b.move();
        break;

        case 3:
            tent a;
            a.draw();
            a.move();
        break;

        case 4:
            complexshape oj;
            oj.create();
            oj.draw();
            oj.hold();
            oj.create();
            oj.move();
            oj.hold();
        break;
    }
    }

}