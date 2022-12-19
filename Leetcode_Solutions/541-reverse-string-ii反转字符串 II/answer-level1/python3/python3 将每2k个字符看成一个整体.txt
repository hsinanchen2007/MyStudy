### 解题思路
时间复杂度：O(n)

### 代码

```python3
class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        res=''
        for i in range(0,len(s),2*k):
            res+=s[i:i+k][::-1]+s[i+k:i+2*k]
        return res
    






```