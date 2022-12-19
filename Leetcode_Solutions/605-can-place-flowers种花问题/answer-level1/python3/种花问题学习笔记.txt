### 解题思路
根据官方的贪心算法写的，
当测试用例为[0]，三个条件为flowerbed[i]==0,i==0,i==len(flowerbed)-1
利用了逻辑判断的短路特性，不需要考虑list的溢出


### 代码

```python3
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count=0
        # if len(flowerbed)==1 and flowerbed[0]==0:
        #     count = 1
        #     reutrn count>=n
        for i in range(0,len(flowerbed)):
            # if(flowerbed[i]==0 and flowerbed[i+1]==0 and flowerbed[i+2]==0)\
            # or (flowerbed[0]==0 and flowerbed[1]==0)\
            # or (flowerbed[len(flowerbed)-1]==0 and flowerbed[len(flowerbed)-2]==0):
            if flowerbed[i]==0 and (i==0 or flowerbed[i-1]==0) and (i==len(flowerbed)-1 or flowerbed[i+1]==0):
                flowerbed[i] = 1
                count+=1
        return count>=n
```