### 解题思路
        本题若是采用O(n^2)的数组双层遍历解法，会超出时间限制。
        采用O(n)的解法：
                        ①：定义start与end分别指向已排续数组的最小值和最大值
                        ②：若nums[start]+nums[end] 小于目标值，start指向后续更大的值
                        ③：反之，end指向前序更小的值。


![下载 (6).png](https://pic.leetcode-cn.com/811c31315346f3df4f8d3a00ebed5d34afd0984f0758a2b375edc827a6e5486b-%E4%B8%8B%E8%BD%BD%20\(6\).png)

### 代码

```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        start = 0
        end = len(nums) - 1
        while end >= start:
            if nums[start]+nums[end] < target:
                start += 1
            elif nums[start]+nums[end] == target:
                ans.append(nums[start])
                ans.append(nums[end])
                return ans
            else:
                end -= 1
        return ans
```