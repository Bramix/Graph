#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Dijkstra{
private:
int inf = INT_MAX;
int position; 
int n;

public:
vector<int> dijkstra (vector<vector<int> > & matrix, int start){
	n = matrix.size();
	vector <bool> used (n, false);
    vector <int> distance(n, 10000);
    vector <int> road(n, start);
    	for (int i = 0; i < n; i++){
    		distance[i] = matrix [start][i];
		}
	distance [start] = 0;
	used [start] = true;
		for (int i = 0; i < n; i++){
			int min = inf;
				for (int j = 0; j < n; j++){
					if(!used[j] && distance[j] < min){
						min = distance[j];
						position = j;
					}
				}
				
			used[position] = true;
			
				for (int j = 0; j < n; j++){
					if(distance [j] > distance[position] + matrix [position][j] && !used[j]  && matrix[position][j] != inf && distance[j] != inf){
						distance [j] = distance[position] + matrix [position][j];
						road [j] = position;
					}
				}
		}
		return distance; 
		//return road;
}
};
