// #include <iostream>
// #include <memory>
// using namespace std;
//
// // struct MyClass {
// //     MyClass() { cout << "gouzao\n"; }
// //     ~MyClass() { cout << "xigou\n"; }
// // };
//
//
// class MyClass {
//     public:
//     int age;
//     string name;
//     MyClass(){cout<<"gouzao"<<endl;}
//     MyClass(int age,string name):age(age),name(name){}
//     ~MyClass(){cout<<"xigou"<<endl;}
// };
// class Base {
//     public:
//     virtual void fun(){cout<<"Base"<<endl;}
// };
// class Son : public Base {
//     public:
//     // void fun(){cout<<"Son"<<endl;}
// };
// int main() {
//
//     Son s1;
//     s1.fun();
//
//     // 创建 unique_ptr
//     // unique_ptr<MyClass> p1(new MyClass()); // RAII：构造时 new
//     //
//     // // unique_ptr<MyClass> p2 = p1; // ❌ 不允许拷贝
//     // unique_ptr<MyClass> p2 = move(p1); // ✅ 可以转移所有权
//     //
//     // // cout << boolalpha;
//     // cout << (p1 == nullptr) << endl; // true，因为 p1 已经不再拥有对象
//     // cout << (p2 != nullptr) << endl; // true，p2 拥有对象
//     //
//     // // MyClass *pMyClass = new MyClass();
//
//     auto p = make_unique<MyClass>(18,"tom");
//
//     // auto p2 = move(p);
//     // unique_ptr<MyClass>p2=move(p);
//     //
//     // cout<<boolalpha;
//     // cout<<(p==nullptr)<<endl;
//     // cout<<p2->age<<endl;
//     //
//     // p2.reset();
//     // cout<<(p2==nullptr)<<endl;
//     // p2=make_unique<MyClass>(20,"yk");
//     // cout<<p2->age<<endl;
//     // cout<<p2->name<<endl;
//     //
//     // unique_ptr<MyClass>p3(p2.release());
//     // unique_ptr<MyClass>p4;
//     //
//     //
//     // p3.release();
//
//     // MyClass *p5=p3.release();
//     // cout<<"p5->age"<<p5->age<<endl;
//     // cout<<"p5->name"<<p5->name<<endl;
//     // delete p5;
//
//     // p4.reset(p3.release());
//     // cout<<p3->age<<endl;
//     // cout<<p3->name<<endl;
//
//     // unique_ptr<MyClass>p5(18,"tom");
//
//     unique_ptr<MyClass> p1 = make_unique<MyClass>(18,"tom");
//     auto p2=p1.get();
//     p2->age = 17;
//     cout<<p1->age<<endl;
//
//     unique_ptr<MyClass> p3 = make_unique<MyClass>(20,"yk");
//     swap(p3,p1);
//     cout<<p3->age<<endl;
//     cout<<p1->age<<endl;
//     return 0; // 程序结束时 p2 析构，自动 delete
// }


// #include <iostream>
// #include <memory>
// #include <vector>
// using namespace std;
//
// class Base {
// public:
//     virtual void hello() { cout << "Base\n"; }
//     virtual ~Base() = default; // ✅ 别忘了虚析构函数，保证释放子类资源
// };
//
// class Derived : public Base {
// public:
//     void hello() override { cout << "Derived\n"; }
// };
//
// int main() {
//     // vector<unique_ptr<Base>> v;
//     // v.push_back(make_unique<Derived>());
//     // v.push_back(make_unique<Base>());
//     //
//     // for (auto& ptr : v) {
//     //     ptr->hello();
//     // }
//
//     vector<Base> vec;
//     vec.push_back(Derived{});
//     vec[0].hello();
// }


//shared_ptr学习
// #include <iostream>
// #include <memory>
// using namespace std;
//
// class MyClass {
//     public:
//     int age;
//     string name;
//     MyClass(){cout<<"gouzao"<<endl;}
//     MyClass(int age,string name):age(age),name(name){}
//     ~MyClass(){cout<<"xigou"<<endl;}
// };
// int main() {
//     shared_ptr<MyClass>p=make_shared<MyClass>(18,"tom");
//     shared_ptr<MyClass> p2=move(p);
//     cout<<p2->age<<endl;
//     cout<<p2.use_count()<<endl;
//     // auto p3=p2.release();
//
//     auto p3=p2.get();
//     cout<<p3->age<<endl;
//     cout<<p2.use_count()<<endl;
//
//     shared_ptr<MyClass> p4=make_shared<MyClass>(19,"yk");
//     shared_ptr<MyClass> p5=p2;
//     cout<<"-------------"<<endl;
//     cout<<"p5->age"<<p5->age<<endl;
//     cout<<"p5->name"<<p5->name<<endl;
//     cout<<p5.use_count()<<endl;
//     cout<<"-------------"<<endl;
//     cout<<"p2->age"<<p2->age<<endl;
//     cout<<"p2->name"<<p2->name<<endl;
//     cout<<p2.use_count()<<endl;
//     cout<<"-------------"<<endl;
//     cout<<"p4->age"<<p4->age<<endl;
//     cout<<"p4->name"<<p4->name<<endl;
//     cout<<p4.use_count()<<endl;
//     swap(p4,p2);
//
//     cout<<"jiaohuanhou"<<endl;
//     cout<<"-------------"<<endl;
//     cout<<"p5->age"<<p5->age<<endl;
//     cout<<"p5->name"<<p5->name<<endl;
//     cout<<p5.use_count()<<endl;
//     cout<<"-------------"<<endl;
//     cout<<"p2->age"<<p2->age<<endl;
//     cout<<"p2->name"<<p2->name<<endl;
//     cout<<p2.use_count()<<endl;
//     cout<<"-------------"<<endl;
//     cout<<"p4->age"<<p4->age<<endl;
//     cout<<"p4->name"<<p4->name<<endl;
//     cout<<p4.use_count()<<endl;
//     cout<<p4->age<<endl;
//     // p2.reset();
//     p5.reset();
//     cout<<p4->age<<endl;
//     cout<<p4.use_count()<<endl;
//     return 0; // 程序结束时 p2 析构，自动 delete
// }



//weak_ptr学习
#include <iostream>
#include <memory>
using namespace std;
class MyClass {
    public:
    int age;
    string name;
    MyClass(){cout<<"gouzao"<<endl;}
    MyClass(int age,string name):age(age),name(name){}
    ~MyClass(){cout<<"xigou"<<endl;}
};
int main() {
    shared_ptr<MyClass>p=make_shared<MyClass>(18,"tom");
    cout<<p->age<<endl;
    cout<<p.use_count()<<endl;
    weak_ptr<MyClass>w=p;
    if (w.expired())cout<<"xiaohui"<<endl;
    else cout<<"cunzai"<<endl;
    w.lock()->age=19;
    cout<<p->age<<endl;
    cout<<w.use_count()<<endl;
    cout<<p.use_count()<<endl;
    cout<<w.lock()->age<<endl;

    return 0;
}
//循环引用