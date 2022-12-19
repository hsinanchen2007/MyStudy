### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isNStraightHand(self, hand: List[int], W: int) -> bool:
        import collections
        d = collections.Counter(hand)
        key = sorted(list(d.keys()))
        for item in key:
            if d[item] == 0:
                continue
            for i in range(1,W):
                if item + i not in d or d[item + i] < d[item]:
                    return False
                else:
                    d[item + i] -= d[item]
        return True
```