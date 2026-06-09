### 解题思路
获胜原则：首家必胜原则，不论取哪个， 一定会获胜。
所以，每次都取最小的情况下也会获胜。
取出数组收尾两个， 首家每次取小的。

### 代码

```python
class Solution(object):
    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        
        min_line, max_line = list(), list()
        while len(piles):
            p = [piles.pop(0), piles.pop()]
            if len(piles)%2 == 0:
                min_line.append(min(p))
            else:
                max_line.append(max(p))
        
        if sum(min_line) > sum(max_line):
            return True
        else:
            return False
```

