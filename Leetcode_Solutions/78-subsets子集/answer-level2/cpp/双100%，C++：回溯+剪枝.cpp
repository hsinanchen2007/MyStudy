### 解题思路
见注释

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        if(nums.empty()) return{};
        vector<int> path;
        backtrack(path,nums,0);
        return res;
    }
    void backtrack(vector<int> &path,vector<int> &nums,const int &start)
    {
        //无结束条件，每一个有效节点都是结果之一
        res.push_back(path);
        //选择动作
        for(int i=start;i<nums.size();i++)
        {
            path.push_back(nums[i]);
            backtrack(path,nums,i+1);
            path.pop_back();
        }  
    }
};
```