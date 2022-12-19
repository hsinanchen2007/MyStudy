### 解题思路
主要是在二进制的基础上进行计算，设置一个变量记录进位，用一个循环可以进行计算，重要的是在最后需要考虑是不是多一位，就是最高位还要进位，还有需要扩充方便两个字符串进行等位运算

### 代码

```python
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if a == b == "0":
            return "0"
        num1 = 0
        if len(a) > len(b):
            d = len(a) - len(b)
            b = "0"*d + b
        if len(a) < len(b):
            d = len(b) - len(a)
            a = "0"*d + a
        j = len(a) - 1
        c = ""
        while j >= 0:
            if a[j]!=b[j]:
                if num1 == 1:
                    c = "0" + c
                    num1 = 1
                else:
                    c = "1" + c
                    num1 = 0
            if a[j]==b[j]=="1":
                if num1 == 1:
                    c = "1" + c
                    num1 = 1
                else:
                    c = "0" + c
                    num1 = 1
            if a[j]==b[j]=="0":
                if num1 == 1:
                    c = "1" + c
                    num1 = 0
                else:
                    c = "0" + c
                    num1 = 0
            j = j-1
            if j==-1:
                if num1 == 1:
                    c = "1" + c
        return c
```