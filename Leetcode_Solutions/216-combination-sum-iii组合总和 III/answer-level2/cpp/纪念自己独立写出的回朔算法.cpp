![image.png](https://pic.leetcode-cn.com/5dd28d7e2a833e10ede7dc0b98ea8ddd62457ce1cb8773c31be457fa75857d45-image.png)



```
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void dfs(int start, int k, int n){
        if(accumulate(path.begin(), path.end(), 0) == n && path.size() == k){
            res.emplace_back(path);
            return;
        }
        for(int i = start; i <= 9; i++){
            if(path.size() < k){
                path.emplace_back(i);
                dfs(i + 1, k, n);
                path.pop_back();
            }else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return res;
    }
};
```
