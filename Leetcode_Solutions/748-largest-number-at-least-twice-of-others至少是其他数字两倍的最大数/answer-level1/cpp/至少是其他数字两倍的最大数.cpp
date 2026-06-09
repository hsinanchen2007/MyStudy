## 题解
### 算法分析
1. 公式：nums[maxIndex] >= 2 * nums[i], i = 0..n && i != maxIndex
2. 假设nums[maxIndex]=max(nums)，遍历一遍数组找出最大值下标，再次遍历一遍数组依次
   判断最大值是否满足上述公式，如果存在不满足则返回-1，否则返回maxIndex
### 复杂度分析
+ 时间复杂度：O(n)，n为nums长度
+ 空间复杂度：O(1)，额外消耗：maxIndex
### 源码
```C++ []
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;

        int maxIndex = 0;
        int sumAll = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != maxIndex && nums[maxIndex] < 2 * nums[i])
            {
                return -1;
            }
        }

        return maxIndex;
    }
};
```