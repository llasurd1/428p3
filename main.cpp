#include <string>
#include <array>

using namespace std;

#define INF 9999

void dijkstra(int graph[][], int size, int start) {
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
        int short = INF;
        for(int j = 0; j<size; j++) {
               if(distance[j]<=short && shortest[j]==0) {
                    short = distance[j];
                    index = j; 
               }
        }
        shortest[index] = 1;
        for(int j = 0; j<size; j++) {
            int new = distance[index] + graph[index][j];
            if((shortest[j]==0) && (graph[index][j]!=0) && (distance[index]!=INF) && (new<distance[j])) {
                distance[j] = new;
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
   int a[sizea][sizea] = { {0, 2, 5, 1, 0, 0},
                   {2, 0, 3, 2, 0, 0},
                   {5, 3, 0, 3, 1, 5},
                   {1, 2, 3, 0, 1, 0},
                   {0, 0, 1, 1, 0, 2},
                   {0, 0, 5, 0, 2, 0} };              
  
  int sizeb = 7;
  int b[sizeb][sizeb] = { {0, 2, 4, 0, 0, 7, 0}, 
                  {2, 0, 3, 3, 0, 0, 0},
                  {4, 3, 0, 4, 3, 8, 0},
                  {0, 3, 4, 0, 6, 0, 0},
                  {0, 0, 3, 6, 0, 6, 8},
                  {7, 0, 8, 0, 6, 0, 12},
                  {0, 0, 0, 0, 8, 12, 0} };
   dijkstra(a, sizea, 0);
   dijkstra(b, sizeb, 3);
   
                  
}
