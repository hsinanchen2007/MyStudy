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
        res = 0
        d = dict()
        dd = dict()

        for c in chars:
            if c in d:d[c] += 1
            else:d[c] = 0
            dd[c] = 0
            
        for word in words:
            flag = True
            for w in word:
                if w in d:
                    if dd[w] > d[w]:
                        flag = False
                        break
                    dd[w] += 1
                else:
                    flag = False
                    break
            if flag:
                res += len(word)
            for i in dd:
                dd[i] = 0
                
        return res
```