## 思路:

思路一：排序

通过索引号排序，比如数字`4`放到索引`3`的位置，最后找排序后数组，与索引号没有相差`1`便是重复元素

思路二：绝对值

借用索引号，因为是在`1~n`之间，那么我们可以用索引`0`表示数字`1`，索引`1`表示数字`2`...，当有个数字`num`，我们将`num - 1`的位置的数字取相反数，连续两次取相反数会变回来，便可判断元素出现次数。

所以时间复杂度为$O(n)$

相似题型：[448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

## 代码：

思路一：

```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            while nums[nums[i] - 1] != nums[i]:
                tmp = nums[i]
                # 注意要保持这个位置
                loc = nums[i] - 1
                nums[i] = nums[nums[i] - 1]
                nums[loc] = tmp
        for idx, val in enumerate(nums, 1):
            if val != idx:
                res.append(val)
        return res
```



思路二：

```python
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            loc = abs(nums[i]) - 1
            if nums[loc] < 0:
                res.append(loc + 1)
            nums[loc] = -nums[loc]
        return res
```


