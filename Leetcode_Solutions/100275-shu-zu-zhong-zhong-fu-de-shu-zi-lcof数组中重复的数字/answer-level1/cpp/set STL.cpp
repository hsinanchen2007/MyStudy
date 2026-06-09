### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        set <int> S;
        for(int i=0;i<nums.size();i++)
        {
            if(S.find(nums[i])==S.end())
                S.insert(nums[i]);

            else
            return nums[i];
        }
        return 0;
    }
};
```