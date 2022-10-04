#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int> > &adj, int x, vector<int>&visited, vector<int>&recStack)
{
  visited[x] = 1;
  recStack[x] = 1;
  for(int i = 0; i< adj[x].size(); i++)
  {
    if(!visited[adj[x][i]] && DFS(adj, adj[x][i], visited, recStack))
    {
      return 1;
    }
    else if(recStack[adj[x][i]])
    {
      return 1;
    }
  }
  recStack[x] = 0;
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size());
  vector<int> recStack(adj.size());
  for (int i = 0; i<adj.size();i++)
  {
    if(!visited[i])
    {
      if(DFS(adj,i, visited,recStack))
      {
        return 1;
      }
    }
  }
  return 0;
}

int main(void) {
  //size_t n, m;
  //std::cin >> n >> m;
  int n = 4;
  int m = 4;
  vector<vector<int>> adj = {{1},{2},{0},{0}};
  
  // for (size_t i = 0; i < m; i++) {
  //   int x, y;
  //   std::cin >> x >> y;
  //   adj[x - 1].push_back(y - 1);
  // }
  std::cout << acyclic(adj);
}
