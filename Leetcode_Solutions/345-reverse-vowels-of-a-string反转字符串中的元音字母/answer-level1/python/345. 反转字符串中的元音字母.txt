### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        l, r = 0, n - 1
        tmp = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        list_s = []
        list_s.extend(s)
        while l < r:
            if list_s[l] not in tmp:
                l += 1
            if list_s[r] not in tmp:
                r -= 1
            if list_s[l] in tmp and list_s[r] in tmp:
                temp = list_s[r]
                list_s[r] = list_s[l]
                list_s[l] = temp
                l += 1
                r -= 1
        return "".join(list_s)
```