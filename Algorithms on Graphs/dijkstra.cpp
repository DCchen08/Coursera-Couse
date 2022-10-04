#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::numeric_limits;

const int max_num = numeric_limits<int>::max();

//const int max_num = 1000;

struct Node{
  int index;
  int distance;
  Node(int a = 0, int b = 0):index(a),distance(b){}
};

struct Compare{
  bool operator()(Node a,Node b){
    return a.distance > b.distance;
  }
};



int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  vector<int> dist(adj.size(), max_num);
  // for(int i = 0;i < adj.size();i++){
  //   dist[i] = max_num;
  // }
  dist[s] = 0;
  priority_queue<Node, vector<Node>, Compare> pq;
  pq.push(Node(s,dist[s]));
  while(!pq.empty()){
    Node sb = pq.top();
    pq.pop();
    int u = sb.index;
    for(int i = 0; i < adj[u].size(); i++){
      int v = adj[u][i];
      if(dist[v] > dist[u]+cost[u][i]){
         dist[v] = dist[u]+cost[u][i];
         pq.push(Node(v,dist[v]));
      }

    }
  }

    if(dist[t] == max_num){
      return -1;
    }

    return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  // int n = 4;
  // int m = 4;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  // vector<vector<int> > adj = {
  //   {1,2},
  //   {2},
  //   {},
  //   {0}
  // };

  // vector<vector<int> > cost = {
  //   {1,5},
  //   {2},
  //   {},
  //   {2}
  // };
  int s, t;
  // s = 1;
  // t = 3;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
