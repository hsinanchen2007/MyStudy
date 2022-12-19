## 1 暴力解法

遍历就完事了
```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        str_len = len(needle)
        if str_len == 0:
            return 0
        for i in range(len(haystack) - str_len+1):
            if needle == haystack[i:i+str_len]:
                return i

        return -1
```
## 2.python库函数法--str.index(sub)
```
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle:
            try:
                return haystack.index(needle)
            except ValueError:
                return -1
        
        return 0
```

## 3.python库函数--str.find(sub)
```
class Solution(object):
    def strStr(self,haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if needle:
            return haystack.find(needle)
        else:
            return 0
```

## 4.KMP算法，子串匹配的奥义
