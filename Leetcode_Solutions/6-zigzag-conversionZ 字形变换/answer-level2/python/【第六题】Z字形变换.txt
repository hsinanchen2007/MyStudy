# 题目 Z字形变换
> 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
> 比如输入字符串为 "LEETCODEISHIRING"行数为 3 时，排列如下：
> 

```
L   C   I   R
E T O E S I I G
E   D   H   N
```
> 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
---
## 示例1

```
输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
L   C   I   R
E T O E S I I G
E   D   H   N
```

## 示例2

```
输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
```
---
### 题解 
> 找到Z字的转折点规律是关键
>
> 标记示例字符串各字符所在行数 =='LDREOEIIECIHNTSG'==
> 
> L E E T C O D E I S H I R I N G
>
> 1 2 3 2 1 2 3 2 1 2 3 2 1 2 3 2
> 
> L E E T C O D E I S H I R I N G
>
> 1 2 3 4 3 2 1 2 3 4 3 2 1 2 3 4
>
> 易得规律：转折点在[1,numRows]两端反复
>
> 定义一个计数器，记录当前行数与给定行数间的关系，当行数为1或等于给定行数时，取相反数
> > 
> > 复杂度分析：
> > 
> > 时间复杂度：O(n)，遍历一遍字符串
> >
> > 空间复杂度：O(n)，需要对应的列表存储，总长为字符串长度
---
#### 代码  

``` 
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        # 行数小于2，直接返回
        if numRows < 2:
            return s
        
        # 以字符串构建行列表
        res = ['' for i in range(numRows)]

        spot = - 1 # 转折点
        n = 1 # 计数器
        for str_ in s:
            res[n - 1] = res[n - 1] + str_
            if n == 1 or n == numRows:
                spot = - spot
            n = n + spot

        return ''.join(res)
```
