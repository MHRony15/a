#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main(){
    int gd = DETECT,gm;
    initgraph(&gd, &gm, "");
    double X0 = 100, Y0 = 400, Xmin = 0, Ymin = 0,Xmax = 800, Ymax = 600;
    line(Xmin,Y0,Xmax,Y0);
    line(X0,Ymin,X0,Ymax);

double A,B,C = 0,k1,k2,dt,T;
cout<<"Enter Quantity of A and B: ";
cin>>A>>B;
cout<<"Enter Reaction Constant K1 and K2: ";
cin>>k1>>k2;
dt = 0.01;
T = 5;
delay(500);
for(double t = 0;t < T;t = t + dt ){
    putpixel(t / dt + X0, Y0 - A, RED);
    putpixel(t / dt + X0, Y0 - B, BLUE);
    putpixel(t / dt + X0, Y0 - C, GREEN);
    delay(20);
    A = A + (k2 * C - k1 * A * B) * dt;
    B = B + (k2 * C - k1 * A * B) * dt;
    C = C + (2 * k1 * A * B - 2 * k2 * C) * dt;
}
getch();
closegraph();
    return 0;
}
