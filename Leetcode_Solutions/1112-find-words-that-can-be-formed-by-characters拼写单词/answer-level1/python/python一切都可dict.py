### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        from collections import Counter
        charsDict = Counter([c for c in chars])
        count = 0
        for word in words:
            wordDict = Counter([c for c in word])
            for k in wordDict.keys():
                if k not in charsDict or wordDict[k] > charsDict[k]:
                    break
            else:
                count += len(word)
        return count
```