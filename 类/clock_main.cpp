#include"clock.h"

int main()
{
    // Clock myClock;
    Clock myClock(0, 0, 0);
    myClock.setTime(8, 30, 30);
    myClock.showTime();

    Clock myClock2(myClock); //用A初始化B
    myClock2.showTime();

    Clock a = re_clock(myClock); //用对象作实参 且 函数返回值为对象 
    a.showTime();

    // Clock b = a;
    return 0;
}
