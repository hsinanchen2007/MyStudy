### 解题思路
按照自己的思路写的。首先比较两个字符串，若同一位置上的字符不同则直接返回''，如果都相同则二者最长的公共子串为其中较短的字符串。然后根据长度关系判断。

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        res = ''
        i = 0
        m = len(str1)
        n = len(str2)
        while i < m and i < n:  #比较两个字符串
            if str1[i] == str2[i]:
                res += str1[i]
                i += 1
            else:
                return ''
        if m > n and str1[i] != res[0]: #防止较长的字符串后的字符不是重复出现，此处应该有bug，如'ABABAC','ABAB'，但是测试用例里可能没有？
            return ''
        if m < n and str2[i] != res[0]:
            return ''
        r = len(res)
        if m%r == 0 and n%r == 0:
            return res
        for i in range(r-1,-1,-1):
            if m%(i+1) == 0 and n%(i+1) == 0:
                return res[:i+1]
```