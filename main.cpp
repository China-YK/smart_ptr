#include <iostream>
#include <memory>
using namespace std;

// struct MyClass {
//     MyClass() { cout << "gouzao\n"; }
//     ~MyClass() { cout << "xigou\n"; }
// };


class MyClass {
    public:
    int age;
    string name;
    MyClass(){cout<<"gouzao"<<endl;}
    MyClass(int age,string name):age(age),name(name){}
    ~MyClass(){cout<<"xigou"<<endl;}
};
int main() {
    // 创建 unique_ptr
    // unique_ptr<MyClass> p1(new MyClass()); // RAII：构造时 new
    //
    // // unique_ptr<MyClass> p2 = p1; // ❌ 不允许拷贝
    // unique_ptr<MyClass> p2 = move(p1); // ✅ 可以转移所有权
    //
    // // cout << boolalpha;
    // cout << (p1 == nullptr) << endl; // true，因为 p1 已经不再拥有对象
    // cout << (p2 != nullptr) << endl; // true，p2 拥有对象
    //
    // // MyClass *pMyClass = new MyClass();

    auto p = make_unique<MyClass>(18,"tom");

    // auto p2 = move(p);
    unique_ptr<MyClass>p2=move(p);

    cout<<boolalpha;
    cout<<(p==nullptr)<<endl;
    cout<<p2->age<<endl;

    p2.reset();
    cout<<(p2==nullptr)<<endl;
    p2=make_unique<MyClass>(20,"yk");
    cout<<p2->age<<endl;
    cout<<p2->name<<endl;

    unique_ptr<MyClass>p3(p2.release());
    unique_ptr<MyClass>p4;


    p3.release();

    // MyClass *p5=p3.release();
    // cout<<"p5->age"<<p5->age<<endl;
    // cout<<"p5->name"<<p5->name<<endl;
    // delete p5;

    // p4.reset(p3.release());
    // cout<<p3->age<<endl;
    // cout<<p3->name<<endl;

    // unique_ptr<MyClass>p5(18,"tom");
    return 0; // 程序结束时 p2 析构，自动 delete
}
