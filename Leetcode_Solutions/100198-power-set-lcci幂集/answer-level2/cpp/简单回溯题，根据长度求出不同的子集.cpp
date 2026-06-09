- 简单回溯

```cpp
class Solution {
public:
    int n;
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        if(!n)return res;
        res.push_back({});
        vector<int>temp;
        for(int i=1;i<=n;i++){
            dfs(nums,temp,0,i);
        }
        return res;
    }
    void dfs(vector<int>& nums,vector<int> &current,int pos,int remain){
        if(remain == 0){
            res.push_back(current);
            return ;
        }
        for(int i=pos;i<n;i++){
            current.push_back(nums[i]);
            dfs(nums,current,i+1,remain-1);
            current.pop_back();
        }
    }
};
```