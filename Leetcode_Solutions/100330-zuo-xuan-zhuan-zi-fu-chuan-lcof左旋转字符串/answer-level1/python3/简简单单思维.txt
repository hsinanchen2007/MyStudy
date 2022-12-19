### 解题思路
可变与不可变类型 - 字符串和列表
（1）共同处
按下表取值、切片、用于for循环、用于len()，以及用于in和not in操作符
（2）不同处
列表是“可变的”数据类型，它的值可以添加、删除或改变。但是，字符串是“不可变的”，它不能被更改。尝试对字符串中的一个字符重新复制，将导致TypeError错误。
“改变”一个字符串的正确方式，是使用切片和链接。构造一个“新的”字符串，从老的字符那里复制一些部分。
(3) point
因此，像remove()、append()方法不能用于字符串中

### 代码

```python3
class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        if len(s) >= n:
            for i in range(n):
                s = s[1:] + s[0] 
            return s
        if len(s) < n:
            return s 

```