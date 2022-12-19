```python3
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        dmin, dmid, dmax = sorted([abs(a - b), abs(a - c), abs(b - c)])
        return [0 if dmid == 1 else (dmin > 2) + 1, dmax - 2]
```
0) dmin:三数间距最小值，dmax:三数间距最大值（也就是三数的极差），dmid:不大不小的
1) min_move:
    a) dmid == 1: 表明三数为间距1的紧密排列
    b) dmin == 1 or 2: 表明更小间距的两数之间只有0或1个空，只需要将另一个数移动到它们中间或旁边即可
    c) dmin > 2: 表明更小间距的两数之间有2个或更多的空，需要移动两次
2) max_move:
    三个数之间的极差为dmax，中间的空只有dmax - 1个，减去另一个数，只有dmax - 2个空可供移动
