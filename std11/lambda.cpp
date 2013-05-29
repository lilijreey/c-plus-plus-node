/*
 *  Description: Lambda func
 *               1. 不需要为lambda函数提供返回值，返回值会
 *               根据语义自动推道。
 *               2. 没有函数名
 *               3. 每一个lambda 都会有一个Clousur 闭包
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

void ss(int &x) { x+=3;}
int main() {
    //sort string
#if 0
    vector<string> vs = {"this", "is", "a", "exercise"};
    sort(vs.begin(), vs.end(),
	    [](const string &lh, const string &rh) {
	    return lh.size() < rh.size();
	    }
	);

    for_each(vs.begin(), vs.end(), 
	    [](string &str) { std::cout << str << std::endl ; }
	    );

#endif
    // EE lambda 函数的 upvalue 在[]中指定,
    // 1.值传递：在实参前加=号
    // [=vs]
    // 2.引用传递：在实参前加&号 
    // [&vs]
    // 3.[ = ] 任何被用到的外部变量都by value pass to lambda
    // 4.[ & ] 任何被用到的外部变量都by reference pass to lambda
    // 5.[vs]  默认为穿值
    // 6.[vs, x] 多个参数用，隔开
    // 7.[=, &vs] 只用vs通过ref引用其他都是穿值
    // 8.[&, vs]
   
    //EE 效率 比较 -O几乎相同  -O2 lambda 好
    const int NUM=10000000;
    vector<int> vec(NUM, 0);
    //        -O        -O2
    //real    0m2.474s 0m0.061s
    //user    0m2.120s 0m0.020s
    //sys     0m0.308s 0m0.036s
    //for_each(vec.begin(), vec.end(),ss);
    
    //real    0m2.440s  0m0.060s
    //user    0m2.124s  0m0.028s
    //sys     0m0.264s  0m0.028s
    for_each(vec.begin(), vec.end(), [] (int &x) { x+=3;});

    //list<int> li(NUM, 0);
    //        -O        -O2
    //real    0m1.622s  0m0.820s
    //user    0m1.500s  0m0.696s
    //sys     0m0.116s  0m0.116s
    //for_each(li.begin(), li.end(),ss);
    //real    0m1.641s  0m0.794s
    //user    0m1.552s  0m0.688s
    //sys     0m0.084s  0m0.096s
    //for_each(li.begin(), li.end(), [] (int &x) { x+=3;});


    
    return 0 ;
}


