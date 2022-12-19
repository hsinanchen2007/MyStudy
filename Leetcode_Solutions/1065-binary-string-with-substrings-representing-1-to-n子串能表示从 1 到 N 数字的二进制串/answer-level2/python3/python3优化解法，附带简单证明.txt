易知，对于任意整数n，其二进制表示的字符串均包含右移一位后的子串，即 n/2 取整后的二进制表示。我们注意到末位为1和0的值均包含同一子序列，则不妨设n=2k，则整数序列(k+1,k+2,...2k)的二进制表示将包含整数序列(k+1/2,...k) 的二进制表示。
根据简单归纳得知该序列将包含右移至末尾后所有子序列的求和，即整数序列(1,2...k)。故只需要遍历[N>>1+1, N]的范围即可
```
class Solution:
    def queryString(self, S: str, N: int) -> bool:
        res = True
        if N < 2: return res
        for i in range(N>>1+1,N+1):
            s = str(bin(i))[2:]
            if (s in S):
                res &= True 
            else:
                res &= False
                break
        return res
```
