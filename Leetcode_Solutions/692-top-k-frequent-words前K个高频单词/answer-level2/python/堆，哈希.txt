### 解题思路
竟然还可以这样建堆！[(-freq, word) for word, freq in count.items()]

### 代码

```python3
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        import heapq
        from collections import Counter
        count = Counter(words)
        # return heapq.nlargest(k, count.keys(), key = lambda w: (count[w],w)) # 但是无法保证顺序诶：x = ["i", "love", "leetcode", "i", "love", "coding"],2; y_true = ["i","love"]; y_pred = ["love","i"]
        heap = [(-freq, word) for word, freq in count.items()]
        heapq.heapify(heap)
        return [heapq.heappop(heap)[1] for _ in range(k)]
```