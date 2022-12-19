第一种思路，枚举每个位置放哪个数
经典算法，Y总 永远滴神


```
class Solution {
public:

    int  n;
    vector<bool>st;
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> permute(vector<int>& nums) {
        n  =  nums.size();
        st = vector<bool>(n);
        dfs(nums,0);
        if(n == 0)return ans; 
        return ans;

    }
    void dfs(vector<int>& nums, int u){
        if(u == n){
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < n; i++){
            if(!st[i]){
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums,u + 1);
                st[i] = false;
                path.pop_back();
            }
        }
    }
};
```
