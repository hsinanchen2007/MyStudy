### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        g=nums[0]
        for i in nums:
            g=gcd(g,i)
        return g==1
    def gcd(self,a,b):
        if a==o:
            return b 
        else:
            if a<b:return gcd(b,a)
            else:
                return(a%b,b)
```