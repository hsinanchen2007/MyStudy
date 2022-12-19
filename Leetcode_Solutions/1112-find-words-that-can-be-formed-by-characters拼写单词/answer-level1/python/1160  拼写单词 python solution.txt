### 解题思路
此处撰写解题思路

### 代码

```python
from collections import Counter
class Solution(object):
        

    def countCharacters(self, words, chars):
        """
        :type words: List[str]
        :type chars: str
        :rtype: int
        """
        chr_fre = Counter(chars)
        res = 0
        for word in words:
            flag = True
            word_fre = Counter(word)
            for i in word:
                if word_fre[i] > chr_fre[i]:
                    flag = False
                    break
            if flag:
                res += len(word)
        return res


```




the nice method for this problem