### 解题思路
A-Z存到字符串中s='A-Z'，利用while循环（t>0）,t-1再取余，a=t%26,结果字符串+s[a],t=t//26.本人不善于表达，看代码吧，挺简单的。
![1581768144(1).png](https://pic.leetcode-cn.com/e44774207e2896d71f3c339ee7520fc7e61aa522239c6af4909002365b92c1aa-1581768144\(1\).png)
此处撰写解题思路

### 代码

```python3
class Solution:
    def convertToTitle(self, n: int) -> str:
        s = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        strr = ''
        t = n
        while t>0:
            t -= 1
            a = t%26
            t = t//26
            strr += s[a]
        return strr[::-1]
```