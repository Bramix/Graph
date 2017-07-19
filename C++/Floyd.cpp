#include <iostream>
#include <vector>


using namespace std;


void getRoad(int start, int finish, vector<vector<int> > & matr);

int main()
{
    int n;
    cin >> n;
    //vector<vector<int> > matrix(n, vector<int>(n));
    vector<vector<int> > matrix(n, vector<int>(n));
    vector<vector<int> > road(n, vector<int>(n));
        for (int i = 0; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                cin >> matrix [i][j];
                road[i][j] = j;
            }
        }

        for (int k = 0; k < n; k ++){
            for (int i = 0; i < n ; i++){
                for (int j = 0; j < n; j++){
                    if (matrix [i][j] > matrix[i][k] + matrix[k][j]){
                        matrix [i][j] = matrix[i][k] + matrix[k][j];
                        road[i][j] = road[i][k];
                    }
                }
            }
        }
        for (int i = 0; i < n ; i++){
                cout << endl;
            for (int j = 0 ; j < n ; j++){

                cout << road[i][j] + 1<< " ";
            }
        }
        getRoad(1, 2 , road);

    return 0;
}

 void getRoad(int start, int finish, vector<vector<int> > & matr ){
     cout << start << " ";
     int now = start;
     while(matr[now][finish] != finish){
            cout << matr[now][finish] << " ";
            now = matr[now][finish];
     }
     cout << finish;
 }

