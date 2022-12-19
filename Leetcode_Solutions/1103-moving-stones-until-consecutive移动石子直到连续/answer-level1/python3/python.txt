可以再短一点，但是懒得改了😂
```
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        l = sorted([a,b,c])
        a = l[0]
        b = l[1]
        c = l[2]
        if b - a == 1 and c - b == 1:
            return [0,0]
        elif c - b == 2 or b - a == 2:
            return [1,c - a - 2]
        elif b - a == 1 and c - b != 1:
            return [1,c - b - 1]
        elif b - a != 1 and c - b == 1:
            return [1,b - a - 1]
        elif b - a != 1 and c - b != 1:
            return [2,c - a - 2]
```
