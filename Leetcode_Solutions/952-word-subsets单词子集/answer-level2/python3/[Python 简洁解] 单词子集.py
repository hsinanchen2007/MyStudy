判断子集：单词 b 是单词 a 的子集等同于 b 中出现每种字母都在 a 中出现，并且每种字母在 b 中出现次数小于等于 a 中出现次数。

暴力解法：直觉的想法就是两重遍历，对于 A 中的每个单词 a，判断是不是 B 中的每个单词 b 都是 a 的子集，时间复杂度是 $O(AB)$，超时。

优化解法：遍历 A 中单词是必要的，优化点在于不必要每次都遍历 B 中所有单词。可以事先遍历一次 B 中所有单词，将其处理为一个单词，只要这个单词是 a 的子集，则 B 中所有单词都是 a 的子集。处理的方法很简单，只需要合并每个 b 的字母频率，相同字母取最大值即可。时间复杂度是 $O(A+B)$


```python
from collections import Counter, defaultdict

class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        # 1. 合并 B 所有单词为一个 counter
        b_cnt = defaultdict(lambda: 0)
        for b in B:
            for k, v in Counter(b).items():
                b_cnt[k] = max(b_cnt[k], v)
                
        # 2. 遍历 A 得到通用的单词
        def is_universal(word):
            a_cnt = Counter(word)
            for k in b_cnt:
                if k not in a_cnt or b_cnt[k] > a_cnt[k]:
                    return False
            return True
            
        return [a for a in A if is_universal(a)]
```
