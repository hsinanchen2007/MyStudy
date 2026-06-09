### 解题思路
套模板

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> tmp;
        
        
         test(res, tmp, nums, 0);
        
        return res;
    }

    void test(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums,int m)
    {
        
        res.push_back(tmp);
        for(int i = m; i < nums.size(); i++)
        {
            tmp.push_back(nums[i]);
            test(res, tmp, nums, i + 1);
            tmp.pop_back();
        }
    }
};


```