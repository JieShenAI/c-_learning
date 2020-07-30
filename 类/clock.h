#ifndef _CLOCK_H_
#define _CLOCK_H_

#include<iostream>
using namespace std;

class Clock{
    public:
        // Clock() = default;//指示编译器提供默认构造函数
        Clock(int newH, int newM, int newS);//不能定义返回类型
        void setTime(int newH = 0, int newM = 0, int newS = 0);
        void showTime();
        Clock(const Clock &c);
        Clock re_clock(Clock a);

    private:
        int hour, minute, second;
};

void Clock::setTime(int newH, int newM, int newS){
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime(){
    cout << hour << ":" << minute << ":" << second<<endl;
}

//构造函数
Clock::Clock(int newH, int newM, int newS):
    hour(newH),minute(newM),second(newS){} //hour(newH) 初始化列表

//复制构造函数
Clock::Clock(const Clock &c){
    hour = c.hour;
    minute = c.minute;
    second = c.second;
    cout << "Calling the copy constructor\n";
}

Clock re_clock(Clock a)
{
    // Clock a(-1,-1,-1);
    a.setTime(-1, -1, -1);
    return a;
}

#endif
