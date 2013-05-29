/*
 *  Description:  c++ x11 中其他的一些新特性和函数
 */
#include <stdio.h>

///auto 会自动把 引用去掉
//int& get(){...}
//auto k = get();
//k 是int 而不是 int&

//EE "std::addressof"
//efined in <memory> header
//去的一个对象的实际地址，就算&被重载
//e.g addressof(x);


///decltype
//compile-time 表达是类型识别

void oo(int &num)
{
  num

}

//EE remove_reference
//EE is_reference
//EE is_lvalue_reference
//EE is_rvalue_reference
//EE integral_constant
//EE is_same
//... type traits

int main() {

    
	return 0 ;
}


