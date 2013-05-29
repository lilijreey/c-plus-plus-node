/*
 * =====================================================================================
 *
 *       Filename:  iterator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2011 09:14:32 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lilijreey (), lilijreey@Gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include	<iostream>
#include	<vector>
#include	<string>
#include	<algorithm>
#include	<iterator>
using namespace std ;
int main() {
	int i = 1 ;
	vector<int> v ;
	v.push_back(i++) ;
	v.push_back(i++) ;
	v.push_back(i++) ;
	v.push_back(i++) ;
	v.push_back(i++) ;
	v.push_back(i++) ;
	v.push_back(i++) ;


	vector<int>::const_iterator cit = v.begin() ;
	for (; cit != v.end(); ++cit)
		cout << *cit << ' ' ;

	cout << "\nadvance" << endl ;
	cit = v.begin() ;
	cout << *cit << endl ;

	/*  advance three elements forward */
	advance(cit, 3) ;
	cout << *cit << endl ;

	/* step one element backward */
	advance(cit, -1) ;
	cout << *cit << endl ;

	/*
	 * reverse iterator
	 */
	
	cout << "Reverse" << endl ;
	vector<int>::const_reverse_iterator rcit(v.begin()) ;
	cout << *rcit << endl ; // the value is forward begin()


	vector<int>::const_reverse_iterator rcit2(v.end()) ;
	cout << *rcit2 << endl ; // the value is forward end()

	vector<int>::const_iterator it ;
	it = rcit.base() ;


}

