/*
 *  Description: 右值引用 移动语义 (move semantics)
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
//EE1 形式 T &&
//EE2 右值引用只能引用右值
//c++03时rvalue 只能绑定在const的引用上

///EE move 语义 就是移动数据而非复制数据
///move 语义出发条件
// * 右值对象时(temporary) move 语义会自动触发.
// * 左值对象，需要使用std::move
//1 class本神有move构造函数,使用右之构造函数是
//2 class本神有move operator=() 使用使用优质
//TT doubleVal(const TT& t) {
//4.当没有move语义函数时，并不会出错，而会调用非move语义的函数
//}

/// std::move/1 函数,把一个左值对象x当作一个右值.
// 由于安全原因，具名变量永远不会被当作右值，
// 即使被声明为右值也不行 （int &&a=3)，
// 为了获得左值的右值必须使用 std::move<T>()

//Qus. 返回一个可以进行右值构造语义的对象， 需要申明返回值是右值类型的吗？
//       std::vector<int>&& fun() {} ? 
//       std::vector<int> func() {}  ? 哪个对？
//       func 返回需要使用std::move/1 函数

/// std::is_move_constructible<T>::value 
//   用来检测类型T是否支持右值

///完美转发 
/// std::forward<T>(v) 等同于 static_cast<T&&>(value)
//forward 起到转发作用, 如果 T的类型为 R&， R&&， 转发后类型还是一样的
//
  /// list 中的node 实现
  template<typename _Tp>
    struct _List_node : public __detail::_List_node_base
    {
      ///< User's data.
      _Tp _M_data;

#ifdef __GXX_EXPERIMENTAL_CXX0X__ //Qus. what is forward
      template<typename... _Args>
        _List_node(_Args&&... __args)
	: __detail::_List_node_base(), _M_data(std::forward<_Args>(__args)...) 
        { }
#endif
    };


struct TT{
    TT() { printf ( "default construction\n" );}
    TT(const TT& t) 
        : _vec(t._vec) 
    {printf ( "copy construction\n" );}

    //move 
    TT(TT&& t) 
        : _vec(t._vec) 
    {printf ( "move copy construction\n" );}

    ~TT() {printf ( "destruction\n" );}

    TT& operator=(const TT& other) {printf ( "operator=\n" ); _vec = other._vec ;return *this;}
    TT& operator=(TT&& other) {printf ( "move operator=\n" ); _vec = other._vec ;return *this;}

    void ss() {printf ( "ss\n" );}
    std::vector<int>  _vec;

    std::vector<int>::iterator begin(){ return _vec.begin(); }
    std::vector<int>::iterator end(){ return _vec.end(); }
};

TT  newTT() {
    TT t;
    t.ss();
    return t;
}


void ss(const int& i) {printf ( "addr:%p\n", &i );} //const 引用
void s1(const int&& i) {printf ( "addr:%p\n", &i );} //const rvalue 引用 参数只能是right value
void s2(int && i){printf ( "addr:%p\n", &i );}

template <typename T> void mySwap(T&a, T&b) 
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T> void myMoveSwap(T&a, T&b) 
{
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}


int main() {
#if 0
    ss(0);
    s1(0);
    s2(0);
    int i=23;
    //s1(i); 2(i);error i is a leftValue
#endif

#if 0
    std::string str="Hello string";
    std::vector<std::string> v;

    v.push_back(str);
    std::cout << "str1: " << str << "\n";

    //EE std::move in utility header file
    //move(x) 意味着可以把x作为一个右值
    v.push_back(std::move(str));
    std::cout << "str2: " << str << "\n";
    std::cout << "v[0]" << v[0] << "\n";
    std::cout << "v[1]" << v[1] << "\n";
#endif

#if 1
    // TT a = TT(); //这个被优化掉了，一会调用一次default const ,move构造函数不会用，
    //TT a (std::move(TT())); //只用使用move函数时才会调用move constructor 
    //    TT a(TT()); what is a?
    //    std::vector<TT> v;
    //    v.push_back(TT());

    TT t3 ;
    t3 = newTT(); //Move =
    //EE 这是就会出发move语义，因为TT有move函数，而newTT返回的是右值
    //    TT t1;
    //    for (int i=0; i < 5; ++i) 
    //	t1._vec.push_back(1);
    //
    //    TT t2;
    //    for (int i=0; i < 5; ++i) 
    //	t2._vec.push_back(2);
    //
    //    printf ( "start-----------------------------\n" );
    //    mySwap(t1,t2);
    //
    //    for (auto i : t1)
    //	printf ( "%d\n",i );
    //    for (auto i : t2)
    //	printf ( "%d\n",i );
    //
    //    myMoveSwap(t1, t2);
    //    for (auto i : t1)
    //	printf ( "%d\n",i );
    //    for (auto i : t2)
    //	printf ( "%d\n",i );
#endif
    return 0 ;
}


