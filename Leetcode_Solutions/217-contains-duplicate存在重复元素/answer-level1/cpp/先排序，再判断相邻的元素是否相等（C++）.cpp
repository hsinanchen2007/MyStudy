### 解题思路
【注意】：先判断该vector是否为空，因为测试用例中有一个"{}"vector。

### 代码

```cpp
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        if (nums.empty())
        {
            return false;
        }
        sort(nums.begin(),nums.end());
        for (int i=0;i!=nums.size()-1;i++)
        {
            if (nums[i]==nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};
```