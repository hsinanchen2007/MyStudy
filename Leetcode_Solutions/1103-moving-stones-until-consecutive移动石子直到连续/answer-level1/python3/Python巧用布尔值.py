布尔值是可以当成1和0直接做加法运算的，在这道题里如果使用布尔值，代码会清晰一点。
```python []
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> list:
        rocks = [a,b,c]
        # 升序排序
        rocks.sort()
        # 最大移动步数就是两边的石头一步一步向中间的靠拢
        max_move = rocks[1]-rocks[0]-1+rocks[2]-rocks[1]-1
        # 最小值有一种特殊情况，就是左边或者右边的石头绕过中间的石头到另一边，并且一步成型
        if rocks[1]-rocks[0] == 2 or rocks[2]-rocks[1]==2:
            min_move = 1
        # 其他的都是不会绕过中间石子的普通情况，或者说，就算绕过了，也没有什么帮助
        # 两边的两个石子，只要不挨着就需要走一步，挨着就不用走
        # 我们用布尔值来表示挨着和不挨着，并且直接用布尔值来做加法运算
        else:
            min_move = bool(rocks[1]-rocks[0]-1)+bool(rocks[2]-rocks[1]-1)
        return [min_move,max_move]
```

