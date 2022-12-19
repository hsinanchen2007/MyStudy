### 解题思路
step1、十进制转换为二进制字符串；
step2、逆序遍历转化好的字符串；
step3、如果此值为'0'，则结果加上该位的十进制数，位数+1；
step4、如果此值为'1'，则结果不变，位数+1；

### 代码

```python3
class Solution:
    def bitwiseComplement(self, N: int) -> int:
        N2b = bin(N)[1:]
        count = 0
        res = 0
        for i in range(len(N2b)-1,0,-1):
            if N2b[i] == '0':
                res += 2**count
                count +=1
            elif N2b[i] == '1':
                count += 1    
        return res

```