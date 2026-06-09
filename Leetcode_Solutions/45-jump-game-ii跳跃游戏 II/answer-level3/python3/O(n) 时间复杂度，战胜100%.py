
a表示当前状态下不需要增加步数的剩余跳动距离，b表示增加一步的剩余跳动距离。
线性遍历一遍，a的跳动距离消耗完之后增加步数，同时把b赋给a
```python []
class Solution:
    def jump(self, nums: List[int]) -> int:
        res = 0
        a = 0
        b = 0
        for e in nums[:-1]:
            if e > b:
                b = e
            if a == 0:
                a = b
                res += 1
            a -= 1
            b -= 1
        return res
```

