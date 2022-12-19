### 解题思路
通过分治，将每一个单词分为左右两部分，判断这两部分是否都存在于列表中。

### 代码

```python3
class Solution:
    def longestWord(self, words: List[str]) -> str:
        def split(words,word):
            for i in range(len(word)):
                left = word[:i]
                right = word[i:]
                if left in words:
                    if right in words:
                        return True
                    elif split(words,right):
                        return True
            return False
        if not words:
            return ""
        res = ""
        a = []
        for word in words:
            if split(words,word):
                if len(word) > len(res):
                    res = word
                elif len(word) == len(res):
                    res = min(word,res)         
        return res
        
                    
        
        
```