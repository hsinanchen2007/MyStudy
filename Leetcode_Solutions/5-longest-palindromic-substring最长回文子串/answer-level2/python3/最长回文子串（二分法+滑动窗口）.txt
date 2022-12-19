### 解题思路
    系列总长度为n，如果最长回文子序列的长度为m(0<m<=n),那么一定存在长度小于m的回文子序列，换言之，如果不存在长度小于m的回文子序列，那么一定也不存在长度大于或等于m的回文子序列。
    鉴于上述思考，寻找最长回文子序列的核心思想包含2点：1）二分法确定最长回文子序列的长度；2）滑动窗口匹配查找相应长度的回文子序列。
    基于二分法的思想，考虑到回文子序列长度可能为奇数或偶数，首先考查是否存在长度为n//2和n//2+1的回文子序列（采用滑动窗口匹配的方法进行确认），如果存在，则继续向上二等分考查是否存在对应长度的回文子序列，否则向下二等分考查是否存在对应长度的回文子序列。
    每次根据考查结果更新最长回文子序列长度的上限或下限，当上限和下限相同或差为1时，即可得到最长回文子序列了。

### 代码

```python3
def isPalindrome(s):
    if not s:return 0
    n=len(s)
    if n==1:return 1
    i=0
    while s[i]==s[n-i-1]:
        i+=1    
        if i==n//2:
            return 1
    return 0
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:return ''
        n=len(s)
        max_len=1
        n_left=0
        n_right=n
        m1=(n_left+n_right)//2
        m2=m1+1
        while m1>n_left and m1<n_right:
            flag=0
            for i in range(n-m1+1):
                s_sub1=s[i:i+m1] if i<n-m1 else s[i:]
                if i<n-m2:
                    s_sub2=s[i:i+m2] 
                elif i==n-m2:
                    s_sub2=s[i:]
                else:
                    s_sub2=''
                if isPalindrome(s_sub2):
                    n_left=m2
                    flag=1
                    max_len=m2
                    break
                elif isPalindrome(s_sub1):
                    n_left=m1
                    max_len=m1
                    flag=1
                    break
            if not flag:
                n_right=m1
            m1=(n_left+n_right)//2
            m2=m1+1
        for i in range(n-m1+1):
            s_sub1=s[i:i+m1] if i<n-m1 else s[i:]
            if i<n-m2:
                s_sub2=s[i:i+m2] 
            elif i==n-m2:
                s_sub2=s[i:]
            else:
                s_sub2=''
            if isPalindrome(s_sub2):
                max_len=m2
                break
            elif isPalindrome(s_sub1):
                max_len=m1
                break
        s_sub=s_sub2 if max_len==m2 else s_sub1
        
        return s_sub
```