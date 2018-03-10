#include "knights.h"

#include <utility>
#include <algorithm>

using std::make_pair;

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

int main() {

	/*
	pair<int,int> position = std::make_pair( 6, 6 );
	vector<pair<int,int>> vPairs = moves(position);
	vector<pair<int,int>> currentMoves = {{0,0},{1,2},{3,3},{4,5},{6,6}};
	
	vector<pair<int,int>> legalPairs = legal_moves(8, currentMoves, position);
	
	for(pair<int,int> p : vPairs){
		
		cout<<p.first << " " << p.second<< ",";		
		
	}
	
	cout<<""<<endl;
	for(pair<int,int> p : legalPairs){
		
		cout<<p.first << " " << p.second<< ",";		
		
	}
	
	
	int dim = 8;
	int midPosition = dim/2;
	vector<pair<int,int>> initialPath = {{midPosition,midPosition}};
	
	pair<Path,bool> endPath = first_tour(dim,initialPath);
	
	cout<<"endPath = "<<"(";
	
	for(pair<int,int> p : endPath.first){
		
		cout<<"("<<p.first <<","<< p.second<<")";		
		
	}
	cout<<","<<endPath.second<<")"<<endl;
	cout<<endl;
	
	*/
    for (int dim = 1; dim <= 8; ++dim) {
        cout << "Looking for tour on a " << dim << " x " << dim << " board\n";
        auto tour = first_tour(dim, Path{{0,0}});
        
        if (!tour.second) {
            cout << "No tour found -- this is okay for boards of size 2,3 or 4 only\n";
        } else {
            for (int row = 0; row < dim; ++row) {
                for (int col = 0; col < dim; ++col) {
                    cout << std::setw(2);
                    cout << std::distance(tour.first.begin(),
                                          std::find(tour.first.begin(), tour.first.end(), make_pair(row,col)));
                    cout << " ";
                }
                cout << endl;
            }
        }
    }

}
