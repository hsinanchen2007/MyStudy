### 解题思路
比较简单和经典的dfs题型，不需要剪枝

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(int start, int n, int k){
      if(tmp.size() == k){
        res.push_back(tmp);
        return;
      }
      
      for(int i = start; i <= n; i++){
        tmp.push_back(i);
        dfs(i + 1, n, k);
        tmp.pop_back();
      }
    }

    vector<vector<int>> combine(int n, int k) {
      if(n == 0 || k == 0)  return res;

      dfs(1, n, k);
      return res;
    }
};
```