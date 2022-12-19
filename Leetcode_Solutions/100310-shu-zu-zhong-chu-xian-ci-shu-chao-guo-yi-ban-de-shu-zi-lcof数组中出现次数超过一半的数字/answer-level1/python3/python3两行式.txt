**题目条件是存在多数元素故可以直接用库函数**
**most_common(1)代表寻找次数最多的前1个组，[0][0]代表第一个数组的第一个数字。
比如{(2,5),(1,2),(3,1),(4,1)}**
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=collections.Counter(nums)
        return count.most_common(1)[0][0]
```
