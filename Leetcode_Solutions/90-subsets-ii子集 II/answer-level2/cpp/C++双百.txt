### 解题思路
如果是1  2 2 2  3 3的话
那么 1 有 0 , 1 次两种选择
那么 2 有 0 , 1 , 2 , 3四种选择
那么 3 有 0 , 1, 2 三种选择
总共是 2 * 3 * 4 = 24种方案
我们只需要计算相同数字的个数
循环遍历即可 

### 代码

```cpp
class Solution {
public:
    
    vector<vector<int>>ans;
    vector<int>path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(nums,0);
        return ans;
    }
    void dfs(vector<int>&nums,int u){
        if(u == nums.size()){
            ans.push_back(path);
            return;
        }
        //计算当前数字的个数
        int k = 0; 
        while(k + u < nums.size() && nums[k + u] == nums[u])k++;
        for(int i = 0 ; i <= k; i++){
            dfs(nums,u + k);
            path.push_back(nums[u]);
        }
        //恢复现场
        for(int i = 0; i <= k; i++)path.pop_back();
    }
};
```