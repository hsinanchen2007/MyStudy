最大的步数：就是一步一步的挪

最小的步数：

1.先找出可能为0的情况，也就是本身就是连续的；

2.找出可能为1的情况，四种情况[1,2,5];[1,4,5];[1,3,4];[1,2,4]



```
class Solution:
    def numMovesStones(self, a: int, b: int, c: int):
        tmp = [a,b,c]
        tmp.sort()
        a,b,c = tmp[0],tmp[1],tmp[2]
        maximum_moves = c - a - 2

        if c - a == 2:
            minimum_moves = 0
        elif b - a == 1 or c - b == 1 or b - a == 2 or c - b == 2:
            minimum_moves = 1
        else:
            minimum_moves =2
        return [minimum_moves,maximum_moves]
```
