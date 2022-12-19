### 解题思路
先sort 这种迭代的思路是每次都push 每个数可以选或者不选，那么重复的条件就是重复的选择了第一个数，确保每次第一次dfs可以进行 后续不能再以相同数字为首进行就ok

### 代码

```cpp
class Solution {
public:


    vector<vector<int>> result;
    void dfs(int num,vector<int> &path,vector<int>&nums){
        
        result.push_back(path);
        for(int i=num;i<nums.size();i++){
            if(i!=num&&nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            dfs(i+1,path,nums);
            path.pop_back();
        }
    }

     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> path;
        dfs(0,path,nums);
        return result;
    }
};
```