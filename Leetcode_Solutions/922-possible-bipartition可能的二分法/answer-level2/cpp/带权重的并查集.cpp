`parent[x].first` 表示 x 的父亲节点的编号（和普通的并查集一样）；
`parent[x].second` 表示 x 与父节点的关系:
- 0 代表 x 与父节点需要在同一组里
- 1 代表 x 与父节点需要在不同组里

对于 x -> y -> z （x的父节点是y，y的父节点是z）:
- parent[x].first = y
- parent[y].first = z

可以得到 x -> z 的关系是：x -> z = x -> y + y -> z，即：
(parent[x].second + parent[y].second) % 2


代码如下：
```
class Solution {
private:
    pair<int, int> find_set(pair<int, int>* parent, int x) {
        if (parent[x].first == x) {
            return parent[x];
        }
        
        pair<int, int> ppx = find_set(parent, parent[x].first);
        parent[x].first = ppx.first;
        // x -> ppx = x -> px + px -> ppx
        parent[x].second = (parent[x].second + ppx.second) % 2;
        
        return parent[x];
    }
    
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      pair<int, int> parent[N + 1];
      for (int i = 1; i <= N; i++) {
          parent[i].first = i;
          parent[i].second = 0;
      }
      
      for (const vector<int>& edge : dislikes) {
          int x = edge[0];
          int y = edge[1];
          pair<int, int> px = find_set(parent, x);
          pair<int, int> py = find_set(parent, y);
          if (px == py) {
              int relation = (px.second + py.second) % 2;
              if (relation == 0) {
                  return false;
              }
          } else {
              parent[py.first].first = px.first;
              // py -> px = py -> y + y -> x + x -> px
              parent[py.first].second = (py.second + 1 + px.second) % 2;
          }
      }
      
      return true; 
  }
};

```
