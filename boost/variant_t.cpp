/**
 * @file     variant_t.cpp
 *           
 *
 * @author   lili  <lilijreey@gmail.com>
 * @date     04/23/2014 09:52:26 AM
 * 
 * 一个union container ，里面的元素可以是任意的类型，但是是单值
 */


#include <string>

#include <boost/variant.hpp>
#include <iostream>

//union {
//  int i;
//  std::string s; //bad
//} u;

/// static_visitor 用来访问variant 必须继承
class my_visitor : public boost::static_visitor<> //for void return type
{
 public:
  void operator()(int i) const 
  { std::cout << "is is a intger " << i << std::endl;}

  void operator()(const std::string &s) const
  { std::cout << "is is a string: " << s << std::endl;}

};

class two_generic : public boost::static_visitor<> //for void return type
{
 public:
  void operator()(int &i) const 
  { i *= 2;}

  void operator()(std::string &s) const
  { s += s;}

};


int main() {
  boost::variant<int, std::string> u("hello, world");
  std::cout << u << std::endl;

  u = 32;
  std::cout << u << std::endl;

  ///EE 当有一个variant 对象时我们不知道他里面到底是那个类型，
  //我们需要使用 static_visitor 模式来访问他
  
  boost::apply_visitor(my_visitor(), u);

  boost::apply_visitor(two_generic(), u);
  std::cout << u << std::endl;

  //使用 boost::apply_visitor 来调用

}
