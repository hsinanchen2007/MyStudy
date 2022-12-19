遍历长度for i in range(1 ~ len(s)/2+1)的所有子字符串（从index=0开始取），所取的子字符串乘以切片数len(s)//i,得到的字符串若和原字符串相等，则返回True


```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        for i in range(1,n//2+1):
            if n % i == 0 and s[:i]*(n//i) == s:
                return True
        return False
                    
```
