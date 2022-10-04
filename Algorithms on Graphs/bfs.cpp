#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
  int max_num = 1000;
  if(s == t){
    return 0;
  }
  vector<int> dist(adj.size());
  for(int i = 0;i<adj.size();i++){
    dist[i] = max_num;
  }
  dist[s] = 0; //initial 0
  queue<int> queue;
  queue.push(s);
  while(!queue.empty()){
    int u = queue.front();
    queue.pop();
    for(int i = 0;i < adj[u].size();i++){
      int v = adj[u][i];
      if(dist[v]==max_num){
        queue.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }

  if(dist[t] != max_num){
    return dist[t];
  }

  return -1;
}

int main() {
  /*
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  */
 int n = 4;
 int m = 4;
 vector<vector<int> > adj = {
  {1,3,2},
  {0,2},
  {1,0},
  {0}
 };
 int s = 1;
 int t = 3;
 std::cout << distance(adj, s, t);
}
