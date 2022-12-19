### 解题思路
相对比较简单dfs
不如39、40的剪枝复杂

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;

    void dfs(int start, int k, int n){
      if(tmp.size() == k && n == 0){
        res.push_back(tmp);
        return;
      }
      
      for(int i = start; i <= 9; i++){
        if(i <= n){
          tmp.push_back(i);
          dfs(i + 1, k, n - i);
          tmp.pop_back();
        }else{
          return;
        }
      }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
      if(n == 0 || k == 0)  return res;

      dfs(1, k, n);
      return res;
    }
};
```