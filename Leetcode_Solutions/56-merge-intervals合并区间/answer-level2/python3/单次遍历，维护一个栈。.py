单次遍历即可完成，思路很简单，
![image.png](https://pic.leetcode-cn.com/2a5d592bcecb93d15ba06cc278d6b7ad2c95ed82e7ed4e60caba1a611b080362-image.png)

"""
先把待合并区间排序，会按照左边界排序，然后维护一个栈，就是把区间放进去，
新进来的区间和栈尾对比，如果左边界落在区间内，那么肯定可以合并，合并然后入栈
如果左边界落在区间外那么就不用合并，入栈即可
"""
```python []
class Solution:
    def merge(self, intervals: list) -> list:
        if not intervals: return []
        intervals.sort()
        result = [intervals[0]]
        for _ in intervals[1:]:
            if _[0] > result[-1][-1]:
                result.append(_)
            else:
                result[-1][-1] = max(result[-1][-1], _[-1])
        return result
```
