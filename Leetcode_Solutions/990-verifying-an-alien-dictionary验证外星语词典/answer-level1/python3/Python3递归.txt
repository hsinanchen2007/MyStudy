### 解题思路
从左到右逐个字母之间比较，有错误的时候返回false，没有问题就继续比较下一个位置的字母

### 代码
```python
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        m = 0
        for word in words:
            m = max(m, len(word))
        d = {order[i]: i for i in range(26)}
        def compare(i, words):
            if i == m: return True
            x = []
            l = '@'
            rec: List[List[str]] = [[]]
            for word in words:
                if i == len(word):
                    x.append(-1)
                    continue
                c = word[i]
                if c != l:
                    l = c
                    rec.append([word])
                else:
                    rec[-1].append(word)
                x.append(d[c])
            if x != sorted(x): return False
            for r in rec:
                if not compare(i+1, r): return False
            return True
        return compare(0, words)
```
