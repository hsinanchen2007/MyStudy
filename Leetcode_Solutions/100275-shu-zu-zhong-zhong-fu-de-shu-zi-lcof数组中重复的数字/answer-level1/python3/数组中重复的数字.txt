### 解题思路
此处撰写解题思路
通过找出数组中最大的数字+1作为新数组的最大的下标数，统计大数的方式，通过牺牲空间来换取时间方式，返回找到的重复的第一个也就是res[0]
### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
            a = [0] * (max(nums)+1)
            for i in nums:
                a[i] += 1
            res = []
            for i in range(len(a)):
                if a[i] >= 2:
                    res.append(i)
            return res[0]
```