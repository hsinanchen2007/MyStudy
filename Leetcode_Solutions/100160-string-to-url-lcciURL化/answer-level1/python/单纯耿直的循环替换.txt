### 解题思路
依旧是耿直的解题思路。
首先用length切割字符串，舍掉不需要的部分
然后生成一个新的空list，对字符串循环判断，根据循环到的字符来判断给空list压入什么字符
当判断为空格时候亚入'%20'，非空格时压入被判断的字符本身，最后使用''.join把list再结合成一个字符串。

分享一个自己遇到的问题：
原本我在解题最初，并没有生成一个新的空list，而是生成了一个新的空字符串，URL_from_S = ''
然后利用+运算把字符或'%20'逐个加进去
虽然算法上来说一样的简单耿直，但是这个代码却在提交时超过时间限制。直到修改为使用list，才得以顺利提交。
本人的十分幼稚的总结是字符串操作相比列表操作来说更费时间。
希望有帮到各位，也望各位高手不吝赐教，十分感谢
### 代码

```python
class Solution(object):
    def replaceSpaces(self, S, length):
        """
        :type S: str
        :type length: int
        :rtype: str
        """
        URL_from_S = []
        for char in S[:length]:
            if char == ' ': 
                URL_from_S.append('%20')
            else:
                URL_from_S.append(char)
        
        return ''.join(URL_from_S)

```