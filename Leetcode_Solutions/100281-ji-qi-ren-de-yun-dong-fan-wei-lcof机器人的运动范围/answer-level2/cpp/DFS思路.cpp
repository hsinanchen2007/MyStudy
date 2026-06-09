### 解题思路
比较简单的DFS，套模板基本就可以了

### 代码

```cpp
class Solution {
public:
    int res = 0;

    int total(int num){
      int sum = 0;
      while(num){
        sum += num % 10;
        num = num / 10;
      }
      return sum;
    }

    void dfs(vector<vector<bool>>& visited, int m, int n, int k, int startX, int startY){
      if(startX < 0 || startY < 0 || startX > m - 1 || startY > n - 1 || visited[startX][startY])
        return;

      visited[startX][startY] = true;
      if(total(startX) + total(startY) > k)
        return;

      res++;
      dfs(visited, m, n, k, startX + 1, startY);
      dfs(visited, m, n, k, startX - 1, startY);
      dfs(visited, m, n, k, startX, startY + 1);
      dfs(visited, m, n, k, startX, startY - 1);
    }

    int movingCount(int m, int n, int k) {
      if(m == 0 || n == 0)  return 0;
      if(k == 0) return 1;

      vector<vector<bool>> visited(m, vector<bool>(n, false));
      dfs(visited, m, n, k, 0, 0);
      return res;
    }
};
```