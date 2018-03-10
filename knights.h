#ifndef KNIGHTS_H
#define KNIGHTS_H

#include <utility>
#include <vector>
#include <algorithm>

using std::pair;
using std::make_pair;
using std::vector;


typedef vector<pair<int,int> > Path;

/** Helper function: adds two pairs of ints */

pair<int,int> operator+(const pair<int,int> & a, const pair<int,int> & b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// TODO - your code goes here

vector<pair<int,int>> moves(pair<int,int> position){

	Path moves = {{+1,-2},{+2,-1},{+2,+1},{+1,+2},{-1,+2},{-2,+1},{-2,-1},{-1,-2}};
	
	Path nextMoves(moves.size());

	transform(moves.begin(), moves.end(),nextMoves.begin(),[&](const pair<int,int> move){return move
+position;});
	return nextMoves;

}


vector<pair<int,int>> legal_moves(int dim, Path currentPath, pair<int,int> position){

	Path nextMoves = moves(position);
	
	Path legalMovesBoard;
	copy_if(nextMoves.begin(),nextMoves.end(),back_inserter(legalMovesBoard),[&](const pair<int,int> p){return (p.first >= 0 && p.first<dim && p.second >= 0 && p.second<dim);});
	
	Path legalMoves;

	copy_if(legalMovesBoard.begin(),legalMovesBoard.end(),back_inserter(legalMoves),[&](const pair<int,int> p){return (find(currentPath.begin(), currentPath.end(),p)==currentPath.end());});

	
	return legalMoves;
}



pair<Path,bool> first_tour(const int & dim, Path path){
	
	// only searching for open tours
	//if a valid tour cannot be found, return a pair of an empty Path, and false.

	// back is the head.

	pair<Path,bool> pear = {path,false};

	if(path.size() == dim*dim){
		
		Path moves = legal_moves(dim,{path.front()},path.front());

		if(find(moves.begin(),moves.end(),path.back())== moves.end()){//open, did not find inside legal moves.

			return {path,true};

		} else {

			path.pop_back();
		
			pear = {path,false};
			return pear;			
					
		}

	}

	// could speed all this up with an ordered moves algorithm. Warnsdorff
	
	Path nextMoves = legal_moves(dim,path,path.back());// always the head here. newest is the head.

	sort(nextMoves.begin(), nextMoves.end(), [&](pair<int,int>& a, pair<int,int>& b) { return legal_moves(dim,path,a).size() < legal_moves(dim,path,b).size();}); 
	
	// if no legal moves, no loop execution.

	for(int i = 0; i< nextMoves.size();++i){
		
		if(pear.second == false){
			// pair contains a path.

			//pair<int,int> p = nextMoves[i];

			path.push_back(nextMoves[i]);

			pear = first_tour(dim, path);// will do the method call first.
			
			path = pear.first;


		}else{
			
			break;			
					
		}	
		
	}
	
	if(nextMoves.empty() || pear.second == false){

		path.pop_back();

		return {path,false};	
		
	}

	return pear;
	
}





// Do not edit below this line

#endif
