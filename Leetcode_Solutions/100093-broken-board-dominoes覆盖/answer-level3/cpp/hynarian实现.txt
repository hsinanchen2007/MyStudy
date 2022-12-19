### 解题思路
hynarian

### 代码

```cpp
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {


public:
  // n * m
  int domino(int n, int m, vector<vector<int>> &broken) {
    vector<int> b;
    for (int i = 0; i < broken.size(); i++)
      b.push_back(broken[i][0] * m + broken[i][1]);

    function<bool(int, int)> valid = [n, m, &b](int x, int y) -> bool {
      if (x < 0 || x >= n)
        return false;
      if (y < 0 || y >= m)
        return false;
      if (b.end() != find(b.begin(), b.end(), x * m + y))
        return false;
      return true;
    };
    vector<int> side;
    vector<unordered_set<int>> adjs(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!valid(i, j))
          continue;
        if (((i % 2 == 0) && (j % 2 == 0)) || (i % 2 == 1) && (j % 2 == 1))
          side.push_back(i * m + j);
       
        for (auto &&dir : {make_pair(-1, 0), make_pair(0, -1)}) {
          int x = i + dir.first;
          int y = j + dir.second;
          if (!valid(x, y))
            continue;
          adjs[i * m + j].insert(x * m + y);
          adjs[x * m + y].insert(i * m + j);
        }
      }
    }
 
    vector<bool> visited;
    vector<int> match;
    match.assign(adjs.size(), -1);
    visited.assign(adjs.size(), false);
    function<bool(int)> maxmatch = [&visited, &adjs, &match,
                                    &maxmatch](int v) -> bool {
      visited[v] = true;
      for (auto &&w : adjs[v]) {
        if (!visited[w]) {
          visited[w] = true;
          if (match[w] == -1 || maxmatch(match[w])) {
            match[w] = v;
            match[v] = w;
            return true;
          }
        }
      }
      return false;
    };
    int matching = 0;
    for (auto it : side) {
      if (-1 == match[it])
        visited.assign(adjs.size(), false);
      if (maxmatch(it))
        matching++;
    }
    return matching;
  }
};

```