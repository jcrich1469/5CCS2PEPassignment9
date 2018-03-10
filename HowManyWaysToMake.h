#ifndef YOUR_TEST_FOR_HOW_MANY_WAYS_TO_MAKE_H
#define YOUR_TEST_FOR_HOW_MANY_WAYS_TO_MAKE_H

//#include "HowManyWaysToMake.h"

#include<iostream>
#include<numeric>
using std::cout;
using std::endl;
//using std::vector;
using std::accumulate;

int testHowManyWaysToMake() {
    // TODO: your test case for question 1b goes inside this function, instead of the next line of code:
    return 0;
    
}

	// 9,{1}
template<typename T> int howManyWaysToMake(T beginIter, const T& endIter, int targetValue){
	// X is the target
	int count = 0;
	
	cout<<"begin value ="<<*beginIter<<endl;
	cout<<"target value ="<<targetValue<<endl;
		
	if(targetValue>0){

		cout<<"target Value gt >0"<<endl;
		count = howManyWaysToMake(beginIter, endIter, targetValue-*beginIter);// count your way to the end...
		cout<<count<<endl;
	
	}

	if(targetValue == 0){

		cout<<count<<endl;
		
		return 1;	

	}
	
	if(targetValue < 0){
		
		return 0;

	}
	
	
	/*
	accumulate(beginIter,endIter,0,[&count,&endIter,&targetValue,&beginIter](int currentSum, int valueAtIndex){
	
		//count = count + howManyWaysToMake(newIter, endIter, targetValue-valueAtIndex);
			currentSum = currentSum + valueAtIndex;
			//count = count + howManyWaysToMake(beginIter, endIter, targetValue-currentSum);
			cout<<"currentSum :"<<currentSum<<endl;
			return count;
		
	});
	*/

	//howManyWaysToMake();
	return count;
		
}


// Do not write any code below this line

#endif
