### 解题思路1
动态规划方法：
![微信图片_20200401223027.png](https://pic.leetcode-cn.com/3182bf3b2bde15823ae7131828aed82d2f78882c0a83852fb80e70d8649f4655-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200401223027.png)

时间复杂度为O(n^2)，空间复杂度为O(n^2)
### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        max_len=0
        max_str=''
        matrix=[[0 for i in range(len(s))] for i in range(len(s))]
        
        if not s or len(s)==1:
            return s
        
        for j in range(len(s)):
            for i in range(0,j+1):
                if j-i<=1:
                    if s[i]==s[j]:
                        matrix[i][j]=1
                        if max_len<j-i+1:
                            max_str=s[i:j+1]
                            max_len=j-i+1
                else:
                    if s[i]==s[j] and matrix[i+1][j-1]:
                        matrix[i][j]=1
                        if max_len<j-i+1:
                            max_str=s[i:j+1]
                            max_len=j-i+1
        return max_str
                        
                    
```
### 解题思路2
中心拓展法：依次选中中心点（奇数为一个点，偶数为两个点），循环向外扩展。
时间复杂度为O(n^2)，空间复杂度为O(1)
### 代码
class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(l,r):
            while(0<=l and r<n and s[l]==s[r]):
                l-=1
                r+=1
            return r-l-1
        if(not s or len(s)==1):
            return s
        n=len(s)
        start=0
        end=0
        for i in range(n):
            len1=expand(i,i)
            len2=expand(i,i+1)
            len_long=max(len1,len2)
            if(len_long>end-start):
                start=i-(len_long-1)//2
                end=i+(len_long)//2
        return s[start:end+1]