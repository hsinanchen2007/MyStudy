### 解题思路
![QQ截图20200216121955.png](https://pic.leetcode-cn.com/208040bafdcd6bbc3f9006090cf962d94ddd098ab84fa10481b1788187636426-QQ%E6%88%AA%E5%9B%BE20200216121955.png)
Python不用考虑运算溢出还是舒服


### 代码

```python3
import functools
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return functools.reduce(lambda x, y: x + y, range(1,len(nums)+1))-functools.reduce(lambda x, y: x + y, nums)
```