```
class Solution {
public:
    int n;
    vector<int> path;    //记录中间过程
    vector<vector<int>> res;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        dfs(nums,0);      //0 表示数字从第一个开始
        return res;
    }
    void dfs(vector<int>& nums,int u)      
    {
        res.push_back(path);
        for(int i=u;i<n;i++)
        {
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
};
```
