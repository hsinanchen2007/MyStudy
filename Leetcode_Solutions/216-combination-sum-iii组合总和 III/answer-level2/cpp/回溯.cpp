

### 代码

```cpp
class Solution {
public:
    vector<int> path{};
    vector<vector<int>> res{};
    void dfs(int begin, int& k, int n){
        if (k == 0 && n == 0){
            res.push_back(path);
            return;
        }
        for (int i = begin; i <= 9; i++){
            if ((n-i) >= 0){
                path.push_back(i); k--;
                dfs(i+1, k, n-i); k++;
                path.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};
```