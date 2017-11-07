#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Graph {
private :
	queue <int> turn;
public:
    vector <int> BFS (vector <vector<int> > & matrix, int start) {
    	vector <bool> used(matrix.size(), true);
    	vector <int> price(matrix.size());
        start --;
	turn.push(start);
	used[start] = false;
	price[start] = 0;
		while(! turn.empty()){
			int end = turn.front();
			turn.pop();
			for (int i = 0; i < matrix[end].size(); i ++){
				int buf = matrix[end][i];
				if(used[buf]){
					turn.push(buf);
					used [buf] = false;
					price [buf] = price[end] + 1;
				 }
			}
			}
        return price;
		//return used;
    }
};
