
## 思路

我们进行一次排序。 然后统计两张牌之间的差值，其中我们分两种情况

- 大小王
- 非大小王

对于非大小王， 如果两个相邻差值等于0，就说明是对子，就不可能是顺子了。 如果是相邻差值大于0，我们进而需要判断大小王个数是否大于等于我们的差值，如果是，我们继续。如果不是，那么肯定不是顺子了。

## 代码


其中ghost表示剩下大小王的个数，由于大小王用数字0表示，排序之后总在最前面，因此下面的算法是可行的。 

```python
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        ghost = 0

        for i in range(len(nums) - 1):
            if nums[i] == 0: ghost += 1
            else:
                if nums[i + 1] == nums[i]: return False 
                ghost -= nums[i + 1] - nums[i] - 1
                if ghost < 0: return False
        return True
```


**复杂度分析**
- 时间复杂度：$O(N * logN)$， 时间复杂度取决于排序本身。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
