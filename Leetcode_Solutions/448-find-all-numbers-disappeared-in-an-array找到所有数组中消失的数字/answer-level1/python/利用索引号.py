## 思路:

思路一：排序

通过索引号排序，比如数字`4`放到索引`3`的位置，最后找排序后数组，与索引号没有相差`1`便是消失元素。

思路二：绝对值

借用索引号，因为是在`1~n`之间，那么我们可以用索引`0`表示数字`1`，索引`1`表示数字`2`...，当有个数字`num`，我们将`num - 1`的位置的数字取相反数，只需把已有元素记录为负号即可。

所以时间复杂度为$O(n)$

相似题型：[442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)

## 代码:

思路1

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            while nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                loc = nums[i] - 1
                nums[i] = nums[nums[i] - 1]
                nums[loc] = tmp
        for idx, val in enumerate(nums, 1):
            if val != idx:
                res.append(idx)
        return res
```

思路2：

```python
class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            loc = abs(nums[i]) - 1
            if nums[loc] > 0:
                nums[loc] = -nums[loc]
        for idx, val in enumerate(nums, 1):
            if val > 0:
                res.append(idx)
        return res
```

