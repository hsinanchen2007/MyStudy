### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hash_map[nums.size()]={0};
        for (int i=0;i<nums.size();i++)
        {
            hash_map[nums[i]]++;
        }
        for (int i=0;i<nums.size();i++)
        {
            if((hash_map[nums[i]]) > 1)
            return nums[i];
        }
        return 0;
    }
};
```