# 思路
线性扫描整个输入字符串，只把不是元音的字母添加到答案里。
# 代码实现
```Python
class Solution(object):
    def removeVowels(self, S):
        """
        :type S: str
        :rtype: str
        """
        res = ""
        for char in S:
            if char not in "aeiou":
                res += char
                
        return res
```
或一行解法
```
class Solution(object):
    def removeVowels(self, S):
        """
        :type S: str
        :rtype: str
        """
        return "".join(char for char in S if char not in "aeiou")
```
# 复杂度分析：
时间复杂度： $O(N)$

空间复杂度： $O(1)$， 如果不考虑输出字符串的空间占用