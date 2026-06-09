** 解题思路**
典型的DFS题目，需要构建题解树，对每一种情况进行排列。需要考虑使用空间来换时间
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len==0) return res;
        bool vis[len];
        vector<int> sol;
        dfs(nums,res,0,vis,sol);
        return res;

    }
    void dfs(vector<int>& nums,vector<vector<int>>& res,int depth,bool* vis,    vector<int>sol){
        if(depth==nums.size()){
             res.push_back(sol);
             return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
               
                sol.push_back(nums[i]);
                vis[i]=1;
                dfs(nums,res,depth+1,vis,sol);
                vis[i]=0;
                sol.pop_back();
            }
        }


    }
};
```

