#ifndef TRADE_H
#define TRADE_H

// TODO your code goes here:


#include <algorithm>
#include <numeric>

//using std::iterator;
using std::accumulate;
using std::max_element;
using std::back_inserter;

template<typename T> int bestProfit(T beginIter, const T& endIter){
	
	// max element of the differences
	int buyPrice = *beginIter;// always buy here, 

	//cout<<*beginIter<<endl;
	int sellPrice = *++beginIter;
	//cout<<sellPrice<<endl;
	int greatestDifference = sellPrice - buyPrice;
	//vector<int> prices{28, 18, 20, 26, 24};
	//cout<<greatestDifference<<endl;
	// starting with initial profits.
	
	accumulate(beginIter,endIter,sellPrice-buyPrice,[&buyPrice, &sellPrice, &greatestDifference](int currentProfit, int priceAtIndex){

		if(buyPrice > priceAtIndex){
		
			buyPrice = priceAtIndex;			
		}
		
		//currentProfit stays the same.
		
		//cout<<"current price : "<<priceAtIndex<<endl;
		// need to manipulated
		
		//cout<<"buy price : "<<buyPrice <<endl;
		sellPrice = priceAtIndex;// sell price always ahead

		currentProfit = sellPrice-buyPrice;

				
		
		if(currentProfit > greatestDifference){
			
			greatestDifference = currentProfit;

			//cout<<"max so far: "<<greatestDifference<<endl;	
			//cout<<buyPrice<<endl;
			//cout<<sellPrice<<endl;
		}

		return currentProfit;	
	});

		
	return greatestDifference;
} 



// Don't write any code below this line

#endif
