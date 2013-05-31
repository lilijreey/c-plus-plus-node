/**
 * @file     function.cpp
 *
 * @brief    <functional> 中 function 函数对象学习笔记
 *
 * @author   lili  lilijreey@gmail.com
 * @date     05/01/2013 10:32:44 PM
 *
 */

// +function是什么？
//   function 是一个模版类，是一个通用的函数包装器 
//   function 的所有特化类都是仿函数类，
//   function 的实例可以是任何可调用的对象(函数指针，其他的仿函数，bind exp,
//   lamda 等)
//
// +为什么需要function?
//  提供了对象级委托(delegate)手段
//   比函数指针更加灵活，因为可以function可以从任何可调用的对象构造，也可
//
// +function能做什么?
//  用来取代虚函数,比虚函数更强大，提供对象级别的委托，不同实例动态设置自己的处理方式
//
//
// +function最佳实践
//
// function的创建
// 函数的类型<R(xxx)> R 是返回类型，


#include <functional>
#include <stdio.h>

void f1() {printf("call f1\n");}
void f2(int i) {printf("call f2 :%d\n", i);}

struct A {
  int memf()  {
    printf("A:memf i:%d\n", i);
    return i;
  }

  int i;
};

class B {
 public:
  void init(const std::function<void(int)> f)
  {_ff = f;}

  void call(int i)
  {
    _ff(i);
  }
 private:
      std::function<void(int)> _ff;
};

int main()
{
  ///@note creat empty function
  std::function<void()> emp;
  //emp 在没复制以前不可以调用
  //ld error can not find ff1 reference
  emp = f1;
  emp(); 

  ///@note creat from common function
  std::function<void()> ff1(f1);
//  std::function<void()> ff1 = f1;
  ff1(); 

  ///@note creat from class member func
  //对用成员函数需要声明期隐含的this类型为第一个参数
  std::function<int(A&)> fmemf(&A::memf);
  A a;
  a.i=10;
  fmemf(a);

  ///@note creat from lembda exp
  std::function<void(int)> flem = [](int i){printf("lembda:%d\n", i);};
  flem(3);
  //写一个返回一个闭包的function

  ///@bug 把GCC4.6.4 搞挂了
  std::function<std::function<int()>(int)> rclouse = [](int i) {
    return [i](){++i;};
  };

  //得到一个初始化i=3 的add function
  std::function<int()> seed3 = rclouse(3);
  printf("%d\n", seed3());

  ///@note create from other std::function
  //std::function<void()> xx = std::bind(xx)

  ///@note use class 
  B b;
  b.init(f2);
  b.call(3);
  printf("sizefo classB:%lu\n", sizeof(b));
  return 0;

}
