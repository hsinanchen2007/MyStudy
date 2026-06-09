### 解题思路
首先要明确的一点就是当前数字之前的数字累计和如果为负数的话那么加上当前数字肯定没当前数字大，直接就该从当前开始。而当前数字之前的数字累计和为正数的话加上当前的数字有可能会增加也有可能会减少，就需要最大值 的判断。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(max < sum)
                max = sum;
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
};
```