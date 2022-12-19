### 解题思路
简单快速

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums)
    {
        unordered_map<int, bool> mymap;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (mymap.count(nums[i]) == 0)
                mymap[nums[i]] = 1;
            else return nums[i];
        }
        return 0;
    }
};
```