```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        vector<bool> visited(nums.size(),false);
        dfs(nums,res,out,visited,0);

        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res,vector<int>& out,vector<bool>& visited,int index){
        if (index == nums.size()){
            res.emplace_back(out);
            return;
        }
        for (int i=0;i<nums.size();++i){
            if (visited[i]) continue;
            visited[i] = true;
            out.emplace_back(nums[i]);
            dfs(nums,res,out,visited,index+1);
            out.pop_back();
            visited[i] = false;
        }
    }
};
```
