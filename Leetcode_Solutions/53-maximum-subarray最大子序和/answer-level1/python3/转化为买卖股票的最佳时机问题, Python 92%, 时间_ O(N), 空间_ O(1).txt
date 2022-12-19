
![Screen Shot 2020-02-15 at 5.26.23 PM.png](https://pic.leetcode-cn.com/79130bfff5539fb59cb528b68e2d9d381f732e0d529960dd4e3e3077da9f2632-Screen%20Shot%202020-02-15%20at%205.26.23%20PM.png)

### 解题思路

将数组中的每个元素和它之前的所有元素累加得到一个新的 `求和数组`, 求最大子数组的问题就转化成了找 `求和数组` 最大差的问题 (考虑到最大差无法包含第一个元素, 需要在 `求和数组` 的开头补一个 0). 

将求和与求最大差写在一个迭代里, 具体代码如下: 

### 代码

```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        min_point, total, max_sum = 0, 0, nums[0]
        for i in nums:
            total += i
            if total < min_point:
                max_sum = max(max_sum, total - min_point)
                min_point = total
            else:
                max_sum = max(max_sum, total - min_point)
        return max_sum
```