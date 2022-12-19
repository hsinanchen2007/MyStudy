```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        temp = [0] + flowerbed + [0]
        for i in range(1, len(temp)-1):
            if temp[i-1]==0 and temp[i]==0 and temp[i+1]==0:
                temp[i] = 1
                n-=1
        return n<=0
```
