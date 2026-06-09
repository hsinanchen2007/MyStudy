### 解题思路
这个题第一眼就想到了leetcod77n个数中k个数的组合，这里n就是nums.size()，k是从0~nums.size()。
```
剪枝：递归中的分支循环i不必从start~nums.size()-1，根据path(保存当前解)的长度和k，可以舍弃重复的分支。也就是i只用从start~nums.size()-(k-path.size())
```
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return res;
        res.push_back({});
        for(int k=1;k<=n;k++){
            dfs(0,k,path,nums);
        }
        return res;
    }
    void dfs(int start,int k,vector<int>& path,vector<int>& nums){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i=start;i<=nums.size()-(k-path.size());i++){
            path.push_back(nums[i]);
            dfs(i+1,k,path,nums);
            path.pop_back();
        }
    }
};
```