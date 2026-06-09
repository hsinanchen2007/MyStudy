1. 第一个字符去匹配, 找到集合S1，剩下的字符只需要匹配S1是否满足条件。
```

class Solution(object):
    def select (self, j_first):
        s1, s2, s3 = 'eiopqrtuwy', 'adfghjkls', 'bcmnvxz'
        if j_first in s1:
            return s1
        elif j_first in s2:
            return s2
        else:
            return s3

    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        R = []
        for i in words:
            j = list(set(i.lower()))
            # first one  j[0:1] is list
            j_first = j[0]
            rule = self.select(j_first)

            flag = True
            for char_j in j:
                if char_j not in rule:
                    flag = False
                    break
            if flag == True:
                R.append(i)
        return R
                             
print Solution().findWords(["Hello", "Alaska", "Dad", "Peace"])
```

2. **set('ac') <= set('eacb') 测试是否 s 中的每一个元素都在 t 中。**
该方法更好

```
class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        R = []
        s1, s2, s3 = 'eiopqrtuwy', 'adfghjkls', 'bcmnvxz'
        for i in words:
            j = set(i.lower())

            if j <= set(s1) or j <= set(s2) or j <= set(s3):
                R.append(i)
        return R
```
