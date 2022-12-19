### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s == " ":
            return True
        letters = collections.Counter(s)
        c = 0
        for i in letters.values():
            if i %2 != 0 :
                c +=1
            
        if c == 1 or c == 0:
            return True
        else:
            return False
```