### 解题思路
* 这题前后放了挺长时间的大概两三个小时去恰了个饭回来接着写的。前面错了好几次。
首先思路是要找到非英文的情况怎么解决，一开始用了``str.isalpha``来做，最后发现了正则的方式会更合适一些~
``re.search('[a-z]',S)``*PS，这里会生成一个Matchobject~*
[这是原出处~感谢大佬~](https://blog.csdn.net/agangz/article/details/80599120)
* 其次是在主程序的问题上，这个可能是我没有理解清楚题的意思吧，一开始就只是在填充`%20`，一直到出现了一道题我发现这个需要用到replace的方法，所以就使用了replace，split，.join三种方法www
* 这次结果还算满意，同时复习了正则和isalpha isdigit。

以及大佬的代码，TQL
class Solution(object):
    def replaceSpaces(self, S, length):
        """
        :type S: str
        :type length: int
        :rtype: str
        """
        return "%20".join(S[:length].split(" "))

[sysu_zhangdao](https://leetcode-cn.com/problems/string-to-url-lcci/solution/python-by-sysu_zhangdao-3/)

### 代码


```python3
import re 
class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        if re.search('[a-z]',S) is None:
            return('%20'*length)
        a = S.strip()
        a = S.split(' ')
        a = ''.join(a)
        print(len(a))
        b = S.replace(' ','%20',length-len(a))
        b = b.split(' ')
        return ''.join(b)

```