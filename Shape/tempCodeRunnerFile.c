#include<iostream>
using namespace std;

class strin{
   string abc;

    public : 
    void getdata(){
        cout<<"Enter string : ";
        cin>>abc;
    }

    strin operator+(strin a){
        strin temp;
        temp.abc=a.abc+abc;
        return temp;
    }


    void display(){
        cout<<abc;
    }
};

int main(){
    strin a,b,c;
    a.getdata();
    b.getdata();
    c=a+b;
    c.display();
}