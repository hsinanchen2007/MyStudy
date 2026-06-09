### 解题思路
仅用字典 简单理解
感谢 sqy提供的思路
### 代码

```python3
class Solution:
    def numMatchingSubseq(self, S: str, words: List[str]) -> int:
        wait = collections.defaultdict(list)
        for word in words:
            wait[word[0]].append(word[1:])
        ans = 0
        for c in S:
            if c in wait:
                temp = wait[c]
                del wait[c]
                for short_word in temp:
                    if short_word!='':
                        wait[short_word[0]].append(short_word[1:])
                    else:
                        ans+=1
        return ans
```