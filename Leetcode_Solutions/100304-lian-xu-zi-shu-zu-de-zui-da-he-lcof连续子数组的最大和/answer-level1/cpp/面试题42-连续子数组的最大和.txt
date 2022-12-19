### 解题思路
这道题的关键在于，理解当前和如果小于0，那么对于之后的累加是副作用，因此应该把下一个元素作为当前和。
然后最大值肯定是每次更新了当前和之后要比较的。

### C++代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //特殊
        if(nums.empty())
            return INT_MIN;
        //功能
        int curSum = 0;
        int maxSum = INT_MIN;
        for(int i = 0;i<nums.size();i++)
        {
            if(curSum <= 0)
            {
                curSum = nums[i];
            }
            else
            {
                curSum += nums[i];
            }
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};
```