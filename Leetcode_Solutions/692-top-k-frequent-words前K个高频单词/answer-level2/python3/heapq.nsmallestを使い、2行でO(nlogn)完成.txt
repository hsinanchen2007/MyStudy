### 解题思路
１、Counterより各文字列のcountを取得
２、ソート
　　条件A：１のcountの降順
　　条件B：文字列のアルファベット順
　　なので、nsmallestを使った

### 代码

```python3
import heapq
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        mapw = collections.Counter(words)
        return heapq.nsmallest(k, mapw, key = lambda t: (-mapw.get(t), t))
        
```