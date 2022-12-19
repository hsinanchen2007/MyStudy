### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x>=0 and x<=9:
            return x
        s = str(x)
        if s[0]=='-'or s[0]=='+':
            if s[-1]=='0':
                rev_s = s[0]+s[1:-1][::-1]
            else:
                rev_s = s[0]+s[1:][::-1]
        else:
            if s[-1]=='0':
                rev_s = s[0:-1][::-1]
            else:
                rev_s = s[0:][::-1]
        if int(rev_s)<= 2**31-1 and int(rev_s) >=-(2**31):
            return int(rev_s)
        else:
            return 0
```
先将int转换为字符串，按有无符号分类讨论，再按末尾是否为0讨论