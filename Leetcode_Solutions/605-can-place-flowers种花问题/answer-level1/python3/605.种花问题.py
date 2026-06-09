### 解题思路
题干解读后就一个条件：三连0位，输出+1
首尾补零解决边界问题，用于判断i=0&i=len(flowerbed)位
### 代码

```python
class Solution(object):
    def canPlaceFlowers(self, flowerbed, n):
        newflowerbed = [0] + flowerbed + [0]
        num = 0
        i = 1
        while i <= len(newflowerbed)-2: 
            if newflowerbed[i-1]==0 and newflowerbed[i]==0 and newflowerbed[i+1]==0:
                i += 2
                num += 1
            else:
                i += 1
        return num >= n
```