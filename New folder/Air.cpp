#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main(){
      int gd = DETECT,gm;
      initgraph(&gd,&gm,"");
      double X0 = 100,Y0 = 400,Xmin = 0,Ymin = 0,Xmax = 800,Ymax = 600;
      line(Xmin,Y0,Xmax,Y0);
      line(X0,Ymin,X0,Ymax);
        int VF ,T;
        cout<<"Enter the speed of fighter: ";
        cin>>VF;
        delay(2000);
        int Time[100],XB[100],YB[100],num,i,XF[100],YF[100],XDis,YDis,Dis;
        ifstream filein;
        filein.open("aircraft.txt");
        string s;
        i=0;
        getline(filein,s);
        stringstream Stime(s);
        while(Stime>>num){
            Time[i] = num;
            i++;
        }
        i=0;
        getline(filein,s);
        stringstream SXB(s);
        while(SXB>>num){
            XB[i] = num;
            i++;
        }
        i=0;
        getline(filein,s);
        stringstream SYB(s);
        while(SYB>>num){
            YB[i] = num;
            i++;
        }
        T = i-1;
        XF[0]=0,YF[0]=0;
        for(i = 0;i < T;i++){
            putpixel(XB[Time[i]] + X0, Y0 - YB[Time[i]], RED);
            putpixel(XF[Time[i]] + X0, Y0 - YF[Time[i]], BLUE);

            XDis = XB[Time[i]] - XF[Time[i]];
            YDis = YB[Time[i]] - YF[Time[i]];
            Dis  = sqrt(abs(XDis * XDis + YDis * YDis));

            XF[Time[i + 1]] = XF[Time[i]] + VF * XDis / Dis;
            YF[Time[i + 1]] = YF[Time[i]] + VF * YDis / Dis;
            //cout<<XB<<" "<<YB<<" "<<XF<<" "<<YF<<" "<<XDis<<" "<<YDis<<" "<<Dis;
            if(Dis <= VF){
            cout<<"Hurrah! The Bomber is Caught!"<<endl;
            goto End;
        }
    }
    cout<<"Failed";
End:
      getch();
      closegraph();

    return 0;
}
