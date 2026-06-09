### 解题思路
![image.png](https://pic.leetcode-cn.com/42e6ec740f7d5d25a81934633827cfdcb4f9ef302501c9e75b2d47142743ad25-image.png)


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
        dic = dict(Counter(chars))
        res=0
        for word in words:
            flag = True
            for j in word:
                if j not in dic:
                    flag = False
                    break
                if word.count(j)>dic[j]:
                    flag = False
                    break
            if flag:
                res+= len(word)
        return res

 

        
                      


                    
```