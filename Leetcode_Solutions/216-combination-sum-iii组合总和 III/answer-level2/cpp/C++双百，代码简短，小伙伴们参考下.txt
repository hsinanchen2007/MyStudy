![image.png](https://pic.leetcode-cn.com/41c0071157e084591a10befd95d02eb066971f8adb2f3c7c66e1674bff65cfde-image.png)

```
class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(int start, int k, int n) {
        if(n == 0 && k == 0) {
            ans.push_back(path);
            return;
        }
        if(k <=0 || n<=0) {
            return;
        }
        for(int i=start; i<=9; i++) {
            if(n - i >=0 && k >= 0) {
                path.push_back(i);
                dfs(i+1, k-1, n-i);
                path.pop_back();         
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};
```
