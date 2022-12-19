### 解题思路
从后向前遍历+结果前插

### 代码

```python3
class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        res=''
        count=0
        for s in S[::-1]:
            if s=='-':
                continue
            if count==K:
                res='-'+res
                count=0
            if s>='a' and s<='z':
                s=chr(ord(s)-32)
            res=s+res
            count+=1
        return res


```