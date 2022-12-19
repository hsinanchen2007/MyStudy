非正则就反锁一点吧，首先把字符串列表化，非字母的变空格，大写变小写，然后过滤掉被ban的词和可能出现的空串，最后统计最大值输出。

```python []
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        p = [*paragraph]
        for i in range(len(p)):
            if p[i].isupper():
                p[i] = p[i].lower()
            elif not p[i].isalpha() and p[i] != ' ':
                p[i] = ' '
        p = ''.join(p).split(' ')
        banned += ['']
        ct = collections.Counter(filter(lambda w: w not in banned, p))
        ans, t = '', 0
        for w in ct:
            if ct[w] > t:
                t = ct[w]
                ans = w
        return ans
```
