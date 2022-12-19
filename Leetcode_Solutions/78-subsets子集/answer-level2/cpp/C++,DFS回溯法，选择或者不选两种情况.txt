```
class Solution {
public:
//DFS常见模板
    void dfs(vector<int>& nums,int pos,vector<int>&list,vector<vector<int>>&ans){
        //下面写一下递归结束条件。
        if(pos==nums.size()){
            ans.push_back(list);//将list放入最终的ans数组中。
            return;
        }
        //下面写一下dfs的主题循环，通常是进行for循环，但是本题只有两种情况，选择或者不选
        list.push_back(nums[pos]);//选择
        dfs(nums,pos+1,list,ans);
        list.pop_back();//不选
        dfs(nums,pos+1,list,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>list;
        dfs(nums,0,list,ans);
        return ans;
    }
};
```
