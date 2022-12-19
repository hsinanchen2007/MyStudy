### 解题思路
核心：数组nums中每个元素有：选 和 不选 两种情况！
### 代码

```cpp
class Solution {
public:
    void dfs(vector<int>& nums,int pos,vector<int>& tmp,vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(tmp);
            return ;
        }
        tmp.push_back(nums[pos]);
        dfs(nums,pos+1,tmp,res);
        tmp.pop_back();
        dfs(nums,pos+1,tmp,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(nums,0,tmp,res);
        return res;
    }
};
```