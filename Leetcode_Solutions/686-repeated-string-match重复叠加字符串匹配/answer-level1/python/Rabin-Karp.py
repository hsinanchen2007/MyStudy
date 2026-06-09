### 解题思路
根据官方题解写的，关键在于A的重复次数，以及Rabin-Karp方法中把字符转换为数字的思路。
最后就是用匹配重复的位置，找出是在A的第几次重复中匹配了B。

### 代码

```python3
class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        l,n=len(A),len(B)
        k=int(n/l+1.99)
        A=A*k
        m=len(A)
        b_count=0
        for i in B:
            b_count=b_count*26+(ord(i)-ord('a'))
        a_count=0
        c=26**(n-1)
        for i in range(m):
            if i>n-1:a_count-=(ord(A[i-n])-ord('a'))*c
            a_count=a_count*26+(ord(A[i])-ord('a'))
            if i>=n-1 and a_count==b_count:return int((i+1)/l+0.99)
        return -1
        
```