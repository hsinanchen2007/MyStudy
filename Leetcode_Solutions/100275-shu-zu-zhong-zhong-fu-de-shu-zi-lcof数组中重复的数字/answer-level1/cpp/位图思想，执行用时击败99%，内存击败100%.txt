### 解题思路
以nums[i]作为索引，nums[nums[i]]的正负表示数值nums[i]是否出现过，如果为负则输出；
针对0元素，可以设一个值zero_num表示0出现的个数，大于1则输出0。

### 代码

```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int zero_num = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zero_num++;
            if(zero_num > 1)
                return 0;
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
        return 0;

    }
};
```