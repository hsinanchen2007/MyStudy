# 思路
  通过下图可知，在**第一行**和**最后一行**两个索引值之间的差值为2（numRows-1），其余行，每一行相邻索引数值差值呈现如下规律：先是相差*2(numRows-1-i)*,之后相差*2i*，之后相互交替，可以用flag变量的正负来代表处于第几个差值，当flag==1时，相差 *2(numRows-1-i)*  ，flag==--1时，相差*2i*。如下图所示：
![z字型题解.png](https://pic.leetcode-cn.com/3a22436a92f74b25d12077be84256c8f843aa327ba4a26d81d6337d95066bd27-z%E5%AD%97%E5%9E%8B%E9%A2%98%E8%A7%A3.png)
代码如下：
```
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows < 2: return s
        res = str()
        for i in range(numRows):            
            j = i
            flag = 1
            while j < len(s):
                res += s[j]
                if i == 0 or i == numRows -1 :  # 第一行和最后一行
                    j += 2 * (numRows - 1)   
                elif flag > 0:
                        j += 2 * (numRows - 1 - i)
                        flag = -flag
                else:
                    j += 2 * i
                    flag = -flag        
        return res
```

