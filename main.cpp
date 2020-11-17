#include <string>
#include <array>
#include <ostream>
#include <vector>
#include <iostream>

using namespace std;

#define INF 9999
int gsize = 0;

void dijkstra(vector<vector<int>> graph, int size, int start) {
    int distance[size];
    int shortest[size];
    for(int i = 0; i<size; i++) {
        shortest[i] = 0;
        if(i!=start) {
            distance[i] = INF;
        }
        else {
            distance[i] = 0;
        }
    }
    for(int i = 0; i<size-1; i++) {
        int index;
        int shor = 0
        for(int j = 0; j<size; j++) {
               if((distance[j]<=shor) && (shortest[j]==0)) {
                    shor = distance[j];
                    index = j; 
               }
        }
        shortest[index] = 1;
        for(int j = 0; j<size; j++) {
            int newt = distance[index] + graph[index][j];
            if((shortest[j]==0) && (graph[index][j]!=0) && (distance[index]!=INF) && (newt<distance[j])) {
                distance[j] = newt;
            }
        }
    }
    cout << "Node   Min Distance" << endl;
    for(int i = 0; i<size; i++) {
        cout << i << "   " <<  distance[i];
    }
}

int main() {
   int sizea = 6;
   gsize = 6;
   vector<vector<int>> a{ {0, 2, 5, 1, 0, 0},
                   {2, 0, 3, 2, 0, 0},
                   {5, 3, 0, 3, 1, 5},
                   {1, 2, 3, 0, 1, 0},
                   {0, 0, 1, 1, 0, 2},
                   {0, 0, 5, 0, 2, 0} };       
  dijkstra(a, sizea, 0);
  
  /*int sizeb = 7;
  gsize = 7;
  int b[gsize][gsize] = { {0, 2, 4, 0, 0, 7, 0}, 
                  {2, 0, 3, 3, 0, 0, 0},
                  {4, 3, 0, 4, 3, 8, 0},
                  {0, 3, 4, 0, 6, 0, 0},
                  {0, 0, 3, 6, 0, 6, 8},
                  {7, 0, 8, 0, 6, 0, 12},
                  {0, 0, 0, 0, 8, 12, 0} };
 
   dijkstra(b, sizeb, 3);*/
   
                  
}
