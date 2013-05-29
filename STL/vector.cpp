/*
 * =====================================================================================
 *
 *       Filename:  vector.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/09/2011 09:35:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lilijreey (), lilijreey@Gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


#include	<vector>
#include	<deque>
#include	<list>
#include	<iostream>
using namespace std ;

int main() {
	vector<int> v ;
	deque<int> d ;
	list<int> l ;
	cout << "v.maxsize(): " << v.max_size() << endl ;
	cout << "v.capacity(): " << v.capacity() << endl ;
	cout << "d.max_size(): " << d.max_size() << endl ;
	cout << "l.max_size(): " << l.max_size() << endl ;

	v.reserve(100) ;
	cout << "v.maxsize(): " << v.max_size() << endl ;
	cout << "v.capacity(): " << v.capacity() << endl ;

	/* reserve less then it own, the reserve not effect */
//	v.reserve(10) 
//	cout << "v.maxsize(): " << v.max_size() << endl ;
//	cout << "v.capacity(): " << v.capacity() << endl ;

	v.assign(10, 4) ;
	cout << "v.maxsize(): " << v.max_size() << endl ;
	cout << "v.capacity(): " << v.capacity() << endl ;
;
}
