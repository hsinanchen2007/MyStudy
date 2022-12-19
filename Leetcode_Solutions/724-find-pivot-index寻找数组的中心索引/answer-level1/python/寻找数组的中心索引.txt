####  方法：前缀和
**算法：**
- `S` 是数组的和，当索引 `i` 是中心索引时，位于 `i` 左边数组元素的和 `leftsum` 满足 `S - nums[i] - leftsum`。
- 我们只需要判断当前索引 `i` 是否满足 `leftsum==S-nums[i]-leftsum` 并动态计算 `leftsum` 的值。

```Python [ ]
class Solution(object):
    def pivotIndex(self, nums):
        S = sum(nums)
        leftsum = 0
        for i, x in enumerate(nums):
            if leftsum == (S - leftsum - x):
                return i
            leftsum += x
        return -1
```

```Java [ ]
class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < nums.length; ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `nums` 的长度。
* 空间复杂度：$O(1)$，使用了 `S` 和 `leftsum` 。