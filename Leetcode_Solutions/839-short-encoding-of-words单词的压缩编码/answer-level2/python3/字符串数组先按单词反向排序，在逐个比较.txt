### 解题思路
字符串数组先按单词反向排序，在逐个比较

### 代码

```python3
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key = lambda x:x[::-1], reverse = True)
        S = words[0]
        for w in words[1:]:
            if not S.endswith(w):
                S = S + '#' + w
        n = len(S)
        if S.endswith('#'):
            return n
        return n + 1
```