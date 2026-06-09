### 解题思路
主要是不要忘了curVec.pop_back()，即回溯后要复原
### 代码

```cpp
class Solution {
public:
    void dfs(vector<vector<int>>& result,vector<int>& curVec,vector<int>& num)
    {
        if(curVec.size() == num.size())
        {
            result.push_back(curVec);
            return;
        }
        for(int i = 0; i < num.size();i++)
        {
            if(find(curVec.begin(),curVec.end(),num[i])  != curVec.end())
            {
                continue;
            }
            else
            {
                curVec.push_back(num[i]);
                dfs(result,curVec,num);
                curVec.pop_back();
            }
        }
        return;

    }
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> curVec;
        for(int i = 0 ; i < nums.size();i++)
        {
            curVec.push_back(nums[i]);
            dfs(result,curVec,nums);
            curVec.pop_back();
        }
        return result;
    }
};
```