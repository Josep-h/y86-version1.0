#include"y86_essence.h"
#include<fstream>
#include<iostream>
//这个函数唯一的目的是把读入的文件写入memory并改写为自己适应的形式
using namespace std;
int turn(char c)
{
    if(c<='9'&&c>='0')
    return c-'0';
    else return c-'a'+10;
}
int decoder()
{
    PC=0;
    ifstream yo("C:\\y86-64\\yo\\marked\\abs-asum-jmp.yo",ios::in);
    char c;
    if(!yo)
    cout<<"wrong"<<endl;
    while(yo.good())
    {
        c=yo.get();
        if(c==' ')
        {
            while(yo.good()&&((c=yo.get())!='\n'));
            continue;
        }
        int num[21];
        int ct=0,num1,num2,num3;
        yo.get();
        num1=yo.get();num2=yo.get();num3=yo.get();
        PC=turn(num1)*16*16+turn(num2)*16+turn(num3);
        yo.get();yo.get();
        while(yo.good())
        {
            c=yo.get();
            if(c==' ')
            break;
            num[ct]=turn(c);
            ct++;
        }
        for(int i=0;i<ct;i+=2)
        {
            memory[PC+i/2]=num[i]*16+num[i+1];
            //cout<<memory[PC+i/2]<<"  ";
        }
        //cout<<endl;
        while(yo.good()&&(yo.get()!='\n'));
    }
    return 0;
}