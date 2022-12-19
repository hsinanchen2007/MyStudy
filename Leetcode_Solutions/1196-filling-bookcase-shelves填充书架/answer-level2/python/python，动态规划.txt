```python
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        dp = [0]  # dp[i]为考虑前i本书时的最小高度
        for i in range(len(books)):
            w, h, j, _min = 0, 0, i, float('inf')
            while j > -1:
                w += books[j][0]
                if w > shelf_width:  # 仅考虑到之前的书能与现在组成一层
                    break
                h = max(h, books[j][1])  # 组成一层后该层的高度
                _min = min(_min, dp[j] + h)  # 不断更新当前最低高度
                j -= 1
            dp.append(_min)
        return dp[-1]
```
