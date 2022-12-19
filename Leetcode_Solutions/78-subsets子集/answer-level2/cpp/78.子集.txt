### 解题思路
方法一：递归法

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> item;
        vector<vector<int>> result;
        result.push_back(item);
        sub(0,nums,result,item);
        return result;
    }
private:
    void sub(int i,vector<int>& nums,
            vector<vector<int>> &result,
            vector<int> &item)
    {       
    if(i>=nums.size())
    {
        return;
    }
    item.push_back(nums[i]);
    result.push_back(item);
    sub(i+1,nums,result,item);
    item.pop_back();
    sub(i+1,nums,result,item);
    }
};
```