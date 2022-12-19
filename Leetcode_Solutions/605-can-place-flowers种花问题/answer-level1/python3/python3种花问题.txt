```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        left=0
        right=0
        for i in range(len(flowerbed)):
            if left==0 and flowerbed[i]==0 and (i+1==len(flowerbed) or flowerbed[i+1]==0):
                flowerbed[i]=1
                n-=1
            left=flowerbed[i]
        return n<=0
```

![image.png](https://pic.leetcode-cn.com/3c7c9e2ad8ddc1105c03f7ebc22b0ee46d26c5bd4dfcfc356c8fdc8850380076-image.png)

