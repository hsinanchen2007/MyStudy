### 解题思路
贪心思路：分为几种情况
#### 1.列表长度<3
*1) 列表中有1：则`return True if n==0 else False`
*2) 列表中没1：则`return True`
#### 2.列表长度>3
*1) 位于两端：则比较0，1或-1，-2元素是否为0
*2）位于中间：则比较i-1,i,i+1元素是否为0

### 代码

```python3
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if len(flowerbed)<2:#特殊情况
            if 1 in flowerbed:return True if n==0 else False
            else:return True
        count=0
        if flowerbed[0]==0 and flowerbed[1]==0:
            count+=1
            flowerbed[0]=1
        if flowerbed[-1]==0 and flowerbed[-2]==0:
            count+=1
            flowerbed[-1]=1
        for i in range(1,len(flowerbed)-1):
            if flowerbed[i]==0 and flowerbed[i-1]==0 and flowerbed[i+1]==0:
                count+=1
                flowerbed[i]=1
        return True if n<=count else False
        
            
```