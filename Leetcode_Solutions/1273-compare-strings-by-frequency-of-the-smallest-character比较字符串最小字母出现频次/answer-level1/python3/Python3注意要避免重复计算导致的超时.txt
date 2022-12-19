```python
class Solution:
    def f(self, s: str) -> int:
        return s.count(min(s))
    
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        res = []
        # 先存储一遍words中的最小值，以免重复计算
        words_cnt = [self.f(word) for word in words]
        for item in queries:
            # 避免重复计算
            f_item = self.f(item)
            res.append(len([1 for cnt in words_cnt if f_item < cnt]))
        return res
```
