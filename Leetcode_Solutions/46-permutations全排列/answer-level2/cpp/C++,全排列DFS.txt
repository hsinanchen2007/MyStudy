这一题注意与78.子集这一题进行区分。
这一题的传入变量pos主要作用是看一个数组中是否有nums.size()个元素，如果有那么加入最终的答案。
```
class Solution {
public:
    void dfs(vector<int>& nums,int pos,vector<int>&list,vector<vector<int>>&ans,vector<bool>&vis){
        if(pos==nums.size()){
            ans.push_back(list);
            return;
        }
        //这里注意需要进行去重操作.去重非常的重要
        //这个需要和78.子集这个问题的区分
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                list.push_back(nums[i]);
                vis[i]=true;
                dfs(nums,pos+1,list,ans,vis);
                vis[i]=false;
                list.pop_back();//回溯，这一步一定不能少。
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>list;
        vector<bool>vis(nums.size(),false);
        dfs(nums,0,list,ans,vis);
        return ans;
    }
};
```
