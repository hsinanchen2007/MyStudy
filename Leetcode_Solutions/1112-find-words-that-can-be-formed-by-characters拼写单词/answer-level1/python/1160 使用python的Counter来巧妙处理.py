### 解题思路
使用了python的counter 和counter 与counter的减法
### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        ans = 0
        charsCounter = collections.Counter(chars)
        for word in words:
            wordCounter = collections.Counter(word)
            if wordCounter-charsCounter == {}:
                ans += len(word)
        return ans
```