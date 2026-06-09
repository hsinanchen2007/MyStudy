### 解题思路
利用数字大小在1-n（n为nums的长度）这个特点，遇到一个数字，就把它摆回它所在的“原位”。如果它已经在原位，检查下一个位置。如果它的原位上的数字和它相同，则返回该数字。
整个过程中，每个数字最多被你动一遍，不使用额外空间，故空间复杂度O(1)，时间复杂度O(n)。

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); )
        {
            if(i + 1 == nums[i])
            {
                i++;
                continue;
            }
            if(nums[nums[i] - 1] == nums[i])
                return nums[i];
            swap(nums[nums[i] - 1],nums[i]);
        }
        return 0;
    }
};
```