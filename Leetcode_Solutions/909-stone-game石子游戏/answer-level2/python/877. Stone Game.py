- 动态规划类型题
- 一次选择A选择收尾最大的, B选择收尾最小的
- A += max(L[0], L[-1]) A每次选择最大的
- B += min(L[i], L[j]) B每次选择最小的

```
class Solution(object):
    def onB(self, piles, i, j, B):
        if piles[i] > piles[j]:
            B += piles[j]
            j -= 1
        else:
            B += piles[i]
            i += 1
        return i, j, B

    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        i, j = 0, len(piles) - 1
        A, B = 0, 0
        while i < j:
            if piles[i] > piles[j]:
                A += piles[i]
                i += 1
                # 处理B
                i, j, B = self.onB(piles, i, j, B)
            else:
                A += piles[j]
                j -= 1
                # 处理B
                i, j, B = self.onB(piles, i, j, B)
        return A > B
```
