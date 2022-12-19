### 解题思路
Two pointers

### 代码

```python
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        s=list(s)
        vowels="aAeEiIoOuU"
        left,right=0,len(s)-1
        while left < right:
            if s[left] not in vowels:
                left += 1
            elif s[right] not in vowels:
                right -= 1
            elif s[left] in vowels and s[right] in vowels:
                s[left],s[right]=s[right],s[left]
                left += 1
                right -= 1
        return "".join(s)


```