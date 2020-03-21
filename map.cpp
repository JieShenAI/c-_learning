//
// Created by tiffa on 2020/3/21.
//

#include<iostream>
#include <cstring>
#include <map>
using namespace std;
void ergodic(map<int,string> m){
    map<int,string>::iterator iter;
    iter = m.begin();
    while(iter != m.end()){
        cout<<iter->first<<"->"<<iter->second<<endl;
        iter++;
    }
}

/*
    //1.insert插入pair
    mapStudent.insert(pair<int,string>(000,"student_zero"));
    //2. insert函数插入value_type数据
    mapStudent.insert(map<int,string>::value_type(001,"student"))
 We can't use the way above-mentioned to insert repeatly.
 bool repeat_insert(map<int,string> m,int key,string value);
 This function can prove it.
 */
bool repeat_insert(map<int,string> &m,int key,string value){
    pair<map<int,string>::iterator,bool> Insert_Pair;
    //We try insert(pair<int,string>(key,value))
    m.insert(pair<int,string>(key,value));

    //Try map.insert(map<int,string>::value_type(key,value))
//    Insert_Pair = m.insert(map<int,string>::value_type(key,value));
    //repeatly insert
    //The result show insert(pair<>()) and insert(map<int,string>::value_type()) fail to insert repeatly.

    string re_value = "second_" + value;
//    Insert_Pair = m.insert(map<int,string>::value_type(key,re_value));
//    if(Insert_Pair.second)
//        return true;
//    else
//        return false;
    //Try to repeat insert with array
    //Attention! This is the only way to change value of map;
    m[key]=re_value;
    if(m[key]==re_value)
        return true;
    else
        return false;
}
bool find(map<int,string> m,int key){
    map<int,string> :: iterator iter;
    // find 查找的关键key出现 返回迭代器指向当前查找元素的位置否则返回map::end()位置
    iter = m.find(key);
    if(iter != m.end()){
        cout<<"Find, the value is "<<iter->second<<endl;
        return true;
    } else {
        cout << " Do not find" << endl;
        return false;
    }
}
void erase(map<int,string> &m,int key){
    map<int,string> :: iterator iter;
    iter = m.find(key);
    m.erase(iter);
    //用关键字刪除
    //int n = m.erase(key); //如果刪除了會返回1，否則返回0
    ergodic(m);
    cout<<"erase all!"<<endl;
    m.erase(m.begin(),m.end());
    ergodic(m);
}
//map的大小
//int nSize = mapStudent.size();
int main() {
    map<int,string> mapStudent;
    //1. insert插入pair
    mapStudent.insert(pair<int,string>(000,"student_zero"));
    //2. insert函数插入value_type数据
    mapStudent.insert(map<int,string>::value_type(001,"student"));
    //3. array方式插入
    mapStudent[123] = "student_123";



    cout<<repeat_insert(mapStudent,113,"113")<<endl;

    ergodic(mapStudent);
    find(mapStudent,113);
    erase(mapStudent,113);
    return 0;
}
