#include <set>
#include <stdio.h>
#include <iostream>
using namespace std;
void Traversal(set<int> s);
int main()
{
    set<int> s;
    set<int> :: iterator iter;
    set<int> :: iterator iter2;
    for(int i =0;i< 15;i++)
        s.insert(i+2);
    Traversal(s);
    printf("\n");
    //s.end() 没有值
    cout<<"s.begin(): "<<*s.begin()<<endl;
    //lower_bound() 返回大于（或等于）某值的第一个元素的迭代器
    cout<<"lower_bound 3: "<<*s.lower_bound(3)<<endl;
    //返回大于某个值元素的迭代器
    cout<<"upper_bound 3: "<<*s.upper_bound(3)<<endl;
    //find()--返回一个指向被查找到元素的迭代器
    //find没找到的话，find()返回的是end()
    if(s.find(100) == s.end()){
        cout<<"find(100) failed!"<<endl;
    }
    cout<<"s.size(): "<<s.size()<<endl;

//    erase(iterator)  ,删除定位器iterator指向的值
//    erase(first,second),删除定位器first和second之间的值
//    erase(key_value),删除键值key_value的值
    s.erase(3);
    Traversal(s);
    iter = s.find(4);
    iter2 = s.find(5);
    s.erase(iter);
    Traversal(s);
    set<int>::iterator iter3;
    cout<<"After erasing iter: "<<*(iter2)<<endl;
    iter3 = iter2++;//6
    cout<<"After erasing iter: "<<*(iter2)<<endl;
    iter3++;
    iter3++;
    /*
     非常重要：
     iter3 += 2;不能这么写，只能写iter3++;
     iter3 = iter2++;
     iter2已经指到下一个去了（iter2已经被改变了）；

     */
    s.erase(iter2,iter3);

    cout<<"iter2: "<<*iter2<<endl;
    Traversal(s);
    //不要重复释放同一个指针，不然会有不好的事发生，
    //个人认为，上一个指针的地址可能已经分配了新的数据。
//    s.erase(iter);
//    Traversal(s);
    return 0;
}
void Traversal(set<int> s){
    set<int>::iterator iter;
    iter = s.begin();
    while(iter != s.end()){
        printf("%d ",*iter);
        iter++;
    }
    printf("\n");
}