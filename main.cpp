#include <string>
#include <array>
#include <ostream>
#include <vector>
#include <iostream>

using namespace std;

//arbitrarily large number
#define INF 9999

void dijkstra(vector<vector<int>> graph, int size, int start) {
    //distance holds the min distances from the chosen node to all other nodes, 
    //shortest holds either a 0 or a 1 for each node, 1 if its been checked, 0 if not
    int distance[size];
    int shortest[size];
    //assign each node as unvisited and with the distance of infinity, except the node we start with, is 0
    for(int i = 0; i<size; i++) {
        shortest[i] = 0;
        if(i!=start) {
            distance[i] = INF;
        }
        else {
            distance[i] = 0;
        }
    }
    //the loop for dijkstras alg
    for(int i = 0; i<size-1; i++) {
        //index is the index of the minimum distance, shor is the shortest distance a node can travel
        int index;
        int shor = INF;
        //finds the minimum distance
        for(int j = 0; j<size; j++) {
               if((distance[j]<=shor) && (shortest[j]==0)) {
                    shor = distance[j];
                    index = j; 
               }
        }
        //mark the node as done
        shortest[index] = 1;
        
        //set the distance values for all the nodes
        for(int j = 0; j<size; j++) {
            int newt = distance[index] + graph[index][j];
            //check if the node hasnt been visited, if there is a vertex, and if the new distance is lower than the old one
            if((shortest[j]==0) && (graph[index][j]) && (distance[index]!=INF) && (newt<distance[j])) {
                distance[j] = newt;
            }
        }
    }
    //printing
    cout << "Node   Min Distance From Node: " << start << endl;
    for(int i = 0; i<size; i++) {
        cout << i << "          " <<  distance[i] << endl;
    }
}

int main() {
   int sizea = 6;
   vector<vector<int>> a{ {0, 2, 5, 1, 0, 0},
                   {2, 0, 3, 2, 0, 0},
                   {5, 3, 0, 3, 1, 5},
                   {1, 2, 3, 0, 1, 0},
                   {0, 0, 1, 1, 0, 2},
                   {0, 0, 5, 0, 2, 0} };       
  dijkstra(a, sizea, 0);
    
  int sizeb = 7;
  vector<vector<int>> b{ {0, 2, 4, 0, 0, 7, 0}, 
                  {2, 0, 3, 3, 0, 0, 0},
                  {4, 3, 0, 4, 3, 8, 0},
                  {0, 3, 4, 0, 6, 0, 0},
                  {0, 0, 3, 6, 0, 6, 8},
                  {7, 0, 8, 0, 6, 0, 12},
                  {0, 0, 0, 0, 8, 12, 0} };
 
   dijkstra(b, sizeb, 3); 
    
   int sizec = 6;
   vector<vector<int>> c{ {0, 8, 1, 6, 0, 0},
                   {8, 0, 2, 2, 0, 0},
                   {1, 2, 0, 2, 7, 9},
                   {6, 2, 2, 0, 4, 0},
                   {0, 0, 7, 4, 0, 7},
                   {0, 0, 9, 0, 7, 0} };       
  dijkstra(c, sizec, 1);
   
                  
}
