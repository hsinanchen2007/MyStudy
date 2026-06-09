### 解题思路
1. **中心扩展法，有2n - 1 个中心，中心既可以是字母**，也可以是两个字符中间
    - 代码中体现即为：expand_centor(s, i, i,nsize) ## 奇数长度
    - expand_centor(s, i, i+1, nsize) ## 偶数长度

### 代码

```python3
class Solution:
    def __init__(self):
        self.res = 0
    def countSubstrings(self, s: str) -> int:
        nsize = len(s)

        if nsize <= 1:
            return nsize 
        
        ## 记录起始位置，返回最长的回文
        #start, end = 0, 0
        for i in range(nsize):
            len1 = self.expand_centor(s, i, i,nsize) ## 奇数
            len2 = self.expand_centor(s, i, i+1, nsize) ## 偶数

            ## 计算起始位置
            '''
            len0 = max(len1, len2)
            if len0 > end - start:
                start = i - (len0-1) // 2
                end = i + len0 // 2
            '''
        ##return s[start:end+1]
        return self.res 
    
    def expand_centor(self, s, l, r, n):

        while l >= 0 and r < n and s[l] == s[r]:
            self.res += 1
            l -= 1
            r += 1
        return r-l -1  ## 本次的长度
```