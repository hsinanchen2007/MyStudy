```
class Solution {
public:
//如何进行去重成为关键...
    void dfs(vector<int>& nums,int pos,vector<int>&list,vector<vector<int>>&ans,vector<int>&vis){
        if(pos==nums.size()){
            ans.push_back(list);
            return;
        }
        //下面进行去重的操作:前一个重复数字选了，后一个重复数字可选可不选，前一个重复数字没有选择，后一个重复数字一定不能选，这样可以防止重复
        //下面是可选的条件，因为无论如何一定可以不选的
        //下面是：第一个数字可以选，或者前后数字不一样，或者前一个数字选了。下面均可以选择。
        if(pos==0||nums[pos-1]!=nums[pos]||vis[pos-1]){
            list.push_back(nums[pos]);
            vis[pos]=1;
            dfs(nums,pos+1,list,ans,vis);
            vis[pos]=0;//下面两步是进行回溯处理
            list.pop_back();
        }
        //不选的情况是一定存在的。
        dfs(nums,pos+1,list,ans,vis);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());//先对去进行排序，方便后面的操作
        vector<vector<int>>ans;
        vector<int>list;
        vector<int>vis(nums.size(),0);
        dfs(nums,0,list,ans,vis);
        return ans;
    }
};
```
