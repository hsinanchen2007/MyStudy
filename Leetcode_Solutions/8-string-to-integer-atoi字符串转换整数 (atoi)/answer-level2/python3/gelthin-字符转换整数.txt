### 解题思路
copy 剑指offer [对应题的题解面试题67](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/solution/gelthin-kong-ge-zi-fu-de-boolzhi-wei-true-by-gelth/)

### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
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