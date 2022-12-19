回溯求解，判断是否当前元素已经被访问过或者当前元素和前一个元素相同同时前一个元素被访问，加以确定当前元素是否应该跳过
```
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<bool> visited(n,false);
        helper(res,tmp,nums,visited);
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int> tmp,vector<int>& nums,vector<bool> visited){
        if(tmp.size()>=nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] || (i!=0 && nums[i]==nums[i-1] && visited[i-1])) continue;
            visited[i]=true;
            tmp.push_back(nums[i]);
            helper(res,tmp,nums,visited);
            visited[i]=false;
            tmp.pop_back();
        }
    }
};
```