#include <iostream>
#include <set>
using namespace std;

/*Student结构体*/
struct Student {
    string name;
    int age;
    string sex;
	//由于set采用的是红黑树存储，必须可比较大小，要么重载<，要么提供比较大小函数。
	
    bool operator < (const Student &b) const {
        /*先比较名字；若名字相同，则比较年龄。小的返回true*/
        if(name < b.name)
            return true;
        else if(name == b.name) {
            if(age < b.age)
                return true;
            else
                return false;
        } else
            return false;
    }
};

int main()
{
    set<Student> stuSet;

    Student stu1, stu2;
    stu1.name = "张三";
    stu1.age = 13;
    stu1.sex = "male";

    stu2.name = "李四";
    stu2.age = 23;
    stu2.sex = "female";

    stuSet.insert(stu1);
    stuSet.insert(stu2);

    /*构造一个测试的Student，可以看到，即使stuTemp与stu1实际上并不是同一个对象，
     *但当在set中查找时，仍会查找成功。这是因为已定义的studentSortCriterion的缘故。
     */
    Student stuTemp;
    stuTemp.name = "张三";
    stuTemp.age = 14;
    cout<<"size: "<<stuSet.size()<<endl;
    cout<<"stuTemp: "<<stuSet.insert(stuTemp).second<<endl;
    cout<<"size: "<<stuSet.size()<<endl;
    set<Student>::iterator iter;
    iter = stuSet.find(stuTemp);
    if(iter != stuSet.end()) {
        cout << (*iter).name << endl;
    } else {
        cout << "Cannot fine the student!" << endl;
    }

    return 0;
}