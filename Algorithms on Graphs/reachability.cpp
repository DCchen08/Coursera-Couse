#include <iostream>
#include <vector>

using namespace std;
int exploring(vector<vector<int> > &adj, int x,int y, vector<int>&visited)
{
  if(x==y)
  {
    return 1;
  }
  visited[x] = 1;
  for(int i=0;i<adj[x].size();i++)
  {
    if(!visited[adj[x][i]])
    {
			if(exploring(adj, adj[x][i], y, visited)) 
      {
				return 1;
      }
    }
  }
  return 0;
} 
int reach(vector<vector<int> > &adj, int x, int y) {
  vector<int>visited(adj.size());
  return exploring(adj, x, y, visited);
}

int main() {
  size_t n, m;



  cout << "Hello" ;
  return 0;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
for (int i = 0; i < adj.size(); i++)
  {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }    
        cout << endl;
  }
  
    return 0;
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
  return 0;
}

 