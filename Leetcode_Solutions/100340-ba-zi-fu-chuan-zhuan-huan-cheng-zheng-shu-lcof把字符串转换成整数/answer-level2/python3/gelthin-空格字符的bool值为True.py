### 解题思路
同主站习题 [主站 8 题](https://leetcode-cn.com/problems/string-to-integer-atoi/)

当无法成功转换时，返回 0
python  2**31, 表示 2的 31 次幂

本题任何无法转换的输入，都输出 0.
一个大的 BUG

### 空格字符的bool值为True, 空格字符也是一个字符，不是空字符串。




### 代码

```python3
class Solution:
    def strToInt(self, str: str) -> int:
        def str2num(A):
            res = 0
            for x in A:
                if '0'<=x<='9':
                    res = res*10 + int(x) 
                else:
                    break
            return res

        n = len(str)
        i = 0
        result = 0
        while i<n:
            # if str[i]: BUG #空字符串也是非空值
            if str[i] != " ":  #
                break
            i += 1
        if i == n: ## 全为空
            return 0
        elif str[i] in {'+', '-'}:
            sign = 1
            if str[i] == '-':
                sign = -1
            result = sign*str2num(str[i+1:])    
        elif '0'<=str[i]<='9':
            result = str2num(str[i:])
        else:
            return 0
        if result > 2**31-1:
            return 2**31-1
        elif result < -2**31:
            return -2**31
        else:
            return result
```