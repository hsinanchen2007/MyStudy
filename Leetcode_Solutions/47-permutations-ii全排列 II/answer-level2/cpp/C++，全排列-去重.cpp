在全排列I的基础上进行修改
```
class Solution {
public:
//在原有的基础上进行修改
    void dfs(vector<int>& nums,int pos,vector<int>&list,vector<vector<int>>&ans,vector<bool>&vis){
        if(pos==nums.size()){
            ans.push_back(list);
            return;
        }
        //如何去重？？？
        //去重的操作与90题子集II是一个去重的道理
        for(int i=0;i<nums.size();i++){
            if(!vis[i]&&(i==0||nums[i-1]!=nums[i]||vis[i-1])){
                list.push_back(nums[i]);
                vis[i]=true;
                dfs(nums,pos+1,list,ans,vis);
                vis[i]=false;
                list.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>list;
        vector<bool>vis(nums.size(),false);
        dfs(nums,0,list,ans,vis);
        return ans;
    }
};
```
