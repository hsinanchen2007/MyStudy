### 解题思路
1. 把N转化为二进制字符串
2. 逆序遍历转化好的字符串
3. 如果当前位为‘0’， 往结果里加上当前二进制位对应的十进制值，位数加1， 继续执行第二步
4. 如果当前位为‘1’， 位数加1， 继续执行第二步

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        b_N = bin(N)
        count = 0
        res = 0
        for i in range(len(b_N)-1, 1, -1):
            if b_N[i] == '0':
                res += 2**count
                count += 1 
            elif b_N[i] == '1':
                count += 1
        return res
```