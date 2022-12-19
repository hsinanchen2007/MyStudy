### 解题思路
琐碎细节没有考虑到，接连错 3次。



### 代码

```python3
class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        if a>b:
            a, b = b, a
        if a>c:
            a, c = c, a
        if b>c:
            b, c = c, b
        # a <b <c

        v2 = c-a-2  # 最大移动次数是每一个中间空格都用上
        if c == b+1 and b == a+1:
            v1 = 0 
        elif c==b+2 or b==a+2:# BUG 135， 最少只要 1 次
            v1 = 1 
        elif c==b+1 or b == a+1: # BUG 125 
            v1 = 1 
        else:
            v1 = 2 # 最小移动次数是尽可能地去靠近 mid, 一步就去靠近

        return [v1, v2]
```