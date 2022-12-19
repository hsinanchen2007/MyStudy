### 解题思路
双指针

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        # 双指针
        if not s:
            return ""
        # s需要转为list,不然交换不了 
        s=list(s)
        l=0
        r=len(s)-1
        while l<r:
            while l<r and s[l] not in 'aeiouAEIOU':
                l+=1
            while l<r and s[r] not in 'aeiouAEIOU':
                r-=1
            if l<r:
                s[l],s[r]=s[r],s[l]
                l+=1
                r-=1
        return ''.join(s)
```