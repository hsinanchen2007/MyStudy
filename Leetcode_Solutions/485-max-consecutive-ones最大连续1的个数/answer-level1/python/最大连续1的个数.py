####  方法一：一次遍历
题目的约束让这个问题变得简单，使得我们可以在一次遍历解决它。

**算法：**
- 用一个计数器 `count` 记录 `1` 的数量，另一个计数器 `maxCount ` 记录当前最大的 `1` 的数量。
- 当我们遇到 `1` 时，`count` 加一。
- 当我们遇到 `0` 时：
	- 将 `count` 与 `maxCount` 比较，`maxCoiunt` 记录较大值。
	- 将 `count` 设为 `0`。
- 返回 `maxCount`。

```java [solution1-Java]
class Solution {
  public int findMaxConsecutiveOnes(int[] nums) {
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < nums.length; i++) {
      if(nums[i] == 1) {
        // Increment the count of 1's by one.
        count += 1;
      } else {
        // Find the maximum till now.
        maxCount = Math.max(maxCount, count);
        // Reset count of 1.
        count = 0;
      }
    }
    return Math.max(maxCount, count);
  }
}
```

```python [solution1-Python]
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = max_count = 0
        for num in nums:
            if num == 1:
                # Increment the count of 1's by one.
                count += 1
            else:
                # Find the maximum till now.
                max_count = max(max_count, count)
                # Reset count of 1.
                count = 0
        return max(max_count, count)
```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 值得是数组的长度。
* 空间复杂度：$O(1)$，仅仅使用了 `count` 和 `maxCount`。


#### 方法二：
- 在 Python 中可以使用 `map` 和 `join` 来解决此问题。
- 使用 `splits` 函数在 `0` 处分割将数组转换成字符串。
- 在获取子串的最大长度就是最大连续 `1` 的长度。
```python [solution2-Python]
def findMaxConsecutiveOnes(self, nums):
  return max(map(len, ''.join(map(str, nums)).split('0')))
```