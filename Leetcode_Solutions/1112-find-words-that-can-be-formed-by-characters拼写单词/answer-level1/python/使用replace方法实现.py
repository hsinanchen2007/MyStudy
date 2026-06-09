### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        ret = 0
        old_chars = chars
        for word in words:
            cnt = 0
            for letter in word: 
                tmp_chars = chars
                chars = chars.replace(letter,"",1)
                if tmp_chars == chars:
                    break
                cnt += 1
            if cnt == len(word):
                ret += cnt
            chars = old_chars

        return ret
```