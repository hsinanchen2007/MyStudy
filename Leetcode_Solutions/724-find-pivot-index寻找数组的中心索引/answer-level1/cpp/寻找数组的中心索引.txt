## 题解
### 算法分析
1. 公式：sumLeft = sumAll - sumLeft - nums[i]
2. 假设sumAll = sum(nums), sumLeft = sum(nums[0]..nums[i]), 如果存在i满足上述公式
   则i为解，否则不存在解
### 复杂度分析
- 时间复杂度：O(n)，n是nums的长度
- 空间复杂度：O(1)，额外消耗：sumAll、sumLeft
### 源码
```C++ []
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int sumAll = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumAll += nums[i];
        }
        
        int sumLeft = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sumLeft == sumAll - sumLeft - nums[i])
            {
                return i;
            }
            sumLeft += nums[i];
        }

        return -1;
    }
};
```