//函数c_str()就是将C++的string转化为C的字符串数组，c_str()生成一个const char *指针，指向字符串的首地址。
//#include<iostream>
//using namespace std;
//int main()
//{
//    char *p = new char [10];
//    string a ="welcome";
//    strcpy(p,a.c_str());
//    cout<<p;
//    return 0;
//}

#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    char str[50];
    //2.取指定长度的字符串。如在下例中，取最大长度为4字节的字符串。
    sscanf("123456 ", "%4s",str);
    //3.取到指定字符为止的字符串。如在下例中，取遇到空格为止字符串。
    sscanf("123456  abcdef","%[^ ]",str);
    //4. 取仅包含指定字符集的字符串。如在下例中，取仅包含1到9和小写字母的字符串。
    sscanf("123456abcdedfBCDEF@#a", "%[1-9a-zA-Z]", str);
    //5. 取到指定字符集为止的字符串。如在下例中，取遇到大写字母为止的字符串。
    sscanf("123456abcdedfBCDEF", "%[^A-Z]", str);
    //6. 用它来分隔类似这样的字符串2006:03:18:
    int a, b, c;
    sscanf("2006:03:18", "%d:%d:%d", &a, &b, &c);
    cout<<a<<" "<<b<<" "<<c<<endl;
    cout<<str<<endl;
    //以及2006:03:18 - 2006:04:18:
    char sztime1[20] = "",sztime2[16]= "";
    sscanf("2006:03:18 - 2006:04:18","%s - %s",sztime1,sztime2);
    cout<<sztime1<<"&"<<sztime2<<endl;

    //%*d和%*s加了（*）表示跳过此数据不读入（也就是不把此数据读入参数中）
    sscanf("1234abcd","%*d%s",str);
    printf("%s\n",str);

    //7. 原问题：iios/12DDWDFF@122 获取/和@之间的字符串怎么做
    const char* s = "iios/12DDWDFF@122";
    char buf[20];
    sscanf(s,"%*[^/]/%[^@]",buf);
    printf("%s\n",buf);

    char user_name[10],password[10];
    sscanf("wpc:123456", "%2s%*[^1]%s", user_name, password);
    cout<<user_name<<" "<<password<<endl;

    string szMsg("0001A");
    unsigned long ulvalue = 0;
    sscanf(szMsg.c_str(),"%5x",&ulvalue);
    cout<<ulvalue<<endl;
    string szMsg2("_Community=public&_MachineName=192.168.6.96&_Port=161&devicetype=_SnmpWin&seid=2");
    char *pPos = strstr(szMsg2.c_str(), "devicetype=");
    if(pPos)
    {
        char *chDevID = new char[strlen(pPos)];
        if(chDevID)
        {
            memset(chDevID, 0, strlen(pPos));
            cout << pPos << endl;
            sscanf(pPos, "devicetype= %[^&]", chDevID);
            cout <<  "Device Type is:" << chDevID << endl;
            delete []chDevID;
        }
    }
    return 0;
}
