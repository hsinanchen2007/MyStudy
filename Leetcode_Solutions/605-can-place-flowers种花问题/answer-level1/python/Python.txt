### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        length=len(flowerbed)
        ans=0
        for i in range(length):
            if flowerbed[i]==0 and ( i==0 or flowerbed[i-1]==0) and ( i==length-1 or flowerbed[i+1]==0):
                flowerbed[i]=1
                ans=ans+1
        if ans>=n:
            return  True
        return False
```