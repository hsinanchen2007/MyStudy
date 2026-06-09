一个小根堆存成本
一个大根堆存利润
每次取成本小于资本的利润放入大根堆，然后每次取大根堆里的最大利润（贪心）
最终利润即是答案

```python3 []
class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        H1, H2 = list(zip(Capital, Profits)), []
        heapify(H1)
        for _ in range(k):
            while H1 and H1[0][0] <= W:
                heappush(H2, -heappop(H1)[1])
            if not H2:
                break
            W -= heappop(H2)
        return W
```
