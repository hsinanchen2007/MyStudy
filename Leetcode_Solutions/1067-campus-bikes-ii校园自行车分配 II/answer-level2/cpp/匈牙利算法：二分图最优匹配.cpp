时间复杂度：O(n^3)

```
class Munkres {
  typedef vector<int> VD;
  typedef vector<VD> VVD;
  typedef vector<int> VI;
public:
  int MinCostMatching(const VVD &cost, VI &Lmate, VI &Rmate) {
    int n = int(cost.size());

    // construct dual feasible solution
    VD u(n);
    VD v(n);
    for (int i = 0; i < n; i++) {
      u[i] = cost[i][0];
      for (int j = 1; j < n; j++) u[i] = min(u[i], cost[i][j]);
    }
    for (int j = 0; j < n; j++) {
      v[j] = cost[0][j] - u[0];
      for (int i = 1; i < n; i++) v[j] = min(v[j], cost[i][j] - u[i]);
    }
    
    // construct primal solution satisfying complementary slackness
    Lmate = VI(n, -1);
    Rmate = VI(n, -1);
    int mated = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Rmate[j] != -1) continue;
        if (fabs(cost[i][j] - u[i] - v[j]) < 1e-10) {
          Lmate[i] = j;
          Rmate[j] = i;
          mated++;
          break;
        }
      }
    }
    
    VD dist(n);
    VI dad(n);
    VI seen(n);
    
    // repeat until primal solution is feasible
    while (mated < n) {
      
      // find an unmatched left node
      int s = 0;
      while (Lmate[s] != -1) s++;
      
      // initialize Dijkstra
      fill(dad.begin(), dad.end(), -1);
      fill(seen.begin(), seen.end(), 0);
      for (int k = 0; k < n; k++) 
        dist[k] = cost[s][k] - u[s] - v[k];
      
      int j = 0;
      while (true) {
        
        // find closest
        j = -1;
        for (int k = 0; k < n; k++) {
          if (seen[k]) continue;
          if (j == -1 || dist[k] < dist[j]) j = k;
        }
        seen[j] = 1;
        
        // termination condition
        if (Rmate[j] == -1) break;
        
        // relax nei***ors
        const int i = Rmate[j];
        for (int k = 0; k < n; k++) {
          if (seen[k]) continue;
          const int new_dist = dist[j] + cost[i][k] - u[i] - v[k];
          if (dist[k] > new_dist) {
            dist[k] = new_dist;
            dad[k] = j;
          }
        }
      }
      
      // update dual variables
      for (int k = 0; k < n; k++) {
        if (k == j || !seen[k]) continue;
        const int i = Rmate[k];
        v[k] += dist[k] - dist[j];
        u[i] -= dist[k] - dist[j];
      }
      u[s] += dist[j];
      
      // augment along path
      while (dad[j] >= 0) {
        const int d = dad[j];
        Rmate[j] = Rmate[d];
        Lmate[Rmate[j]] = j;
        j = d;
      }
      Rmate[j] = s;
      Lmate[s] = j;
      
      mated++;
    }
    
    int value = 0;
    for (int i = 0; i < n; i++)
      value += cost[i][Lmate[i]];
    
    return value;
  }
};

class Solution {
    inline int distance(const vector<int>& worker, const vector<int>& bike) {
      return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
public:
    int assignBikes(const vector<vector<int>>& workers, const vector<vector<int>>& bikes) {
        vector<vector<int>> WBDistance;
        for (const auto& worker: workers) {
          WBDistance.push_back({});
          auto& bd = WBDistance.back();
          for (const auto& bike: bikes) {
            bd.push_back(distance(worker, bike));
          }
        }
        
        const int N = bikes.size();
        for (int i = workers.size(); i < N; ++i) {
          WBDistance.push_back(vector<int>(N, 0));
        }

        vector<int> wL;
        vector<int> bL;
        return Munkres().MinCostMatching(WBDistance, wL, bL);
    }
};
```
