### 解题思路
书中说“本题难度不小，但又即为常见。”


注意子数组一定是连续的。本题的关键是要理解这么一层含义：对于数组 `nums = [5, -9, 6, -2, 3]`，`5` 是否要加 `-9`，取决于 `-9` 后面的正数是否能抵消 `-9` 并还有剩余。

此时再看数组就会明白，`-9` 不能加，而 `-2` 可以，因为 `-2 + 3` 相当于 `+1`。

#### 算法
- 初始化 $sum$，$maxsum$
- 对于每个 $nums[i]$：
    - $sum= max(sum + nums[i], nums[i])$
    - $maxsum = max(sum, maxsum)$
- 返回 $maxsum$

说明一下 $sum= max(sum + nums[i], nums[i])$ 为何可以解决前面的想法：
- 从数组第一个元素开始，首先加上 $5$， $sum=5$;
- 不确定是否加 $-9$，但是先加上，$sum=-4$;
- 加上 $6$，$sum=2$，我们知道 $6$ 并没有完全抵消 $-9$，表现为 $sum<6$，因此重置 $sum=6$。

#### 代码

```python []
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxsum, sum = float('-inf'), float('-inf')
        for i in nums:
            sum = max(sum + i, i)
            maxsum = max(sum, maxsum)
        return maxsum
```
```C++ []
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN;
        int sum = 0;
        for (auto i: nums)
        {
            sum = max(i + sum, i);
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};
```

#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(1)$。