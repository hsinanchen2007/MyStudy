## 思路（哈希表）

由于题目要求返回的数字，而不是索引，因此双指针是可以的。当然hashtable也是可以的，只不过没有利用题目`递增排序 `的要求

## 代码

```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited = set()
        for num in nums:
            if target - num in visited:
                return [target - num, num]
            visited.add(num)
        return []
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$


## 思路（双指针额）

我们考虑使用双指针优化。

## 代码

```python

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        nums.sort()
        l = 0
        r = len(nums) - 1
        while(l < r):
            if (nums[l] + nums[r] < target):
                l += 1
            elif (nums[l] + nums[r] > target):
                r -= 1
            else:
                return [l, r]
        return []

```


**复杂度分析**
- 时间复杂度：$O(logN)$
- 空间复杂度：$O(1)$



你可能会有这样的疑问，为什么双指针是有效的解法？那么就让我们来证明一下算法的正确性。根据题意，我们的目标是找到两个数字，这两个数字的和等于 target。这两个数字可以是任意两个数字，我们怎么找到符合条件的这两个数字呢？我们升序排序之后，分别取首尾元素。如果相加大于 target，那么尾部数字和其他所有的数字相加的结果我们就没有必要看了，肯定都不满足，也就是说最终结果肯定排除了尾部数字，我们只需要移动一下尾指针将其排除即可。同我们不断执行这样的逻辑，直到我们找到满足条件的数字组合。



欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)





