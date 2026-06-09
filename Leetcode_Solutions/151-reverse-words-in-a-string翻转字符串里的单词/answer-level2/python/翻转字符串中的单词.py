这道题目使用python语言来做只需一行代码，思路如下：
(1) 首先使用字符串中的split()函数将字符串中的单词逐个分离出来
(2) 使用Python语言的列表的切片操作以及join函数将步骤(1)得到的列表使用空格逆序连接起来
代码如下：
```
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        return " ".join([ch for ch in s.split()[::-1]])
```
