### 解题思路
此处撰写解题思路
将开头为0和结尾为0的数组等效变形为开头和结尾都是1的数组

### 代码

```python3
import math
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        start, l, res = 0, 0, 0
        if flowerbed[0] == 0:
            flowerbed = [1,0] + flowerbed
        if flowerbed[-1] == 0:
            flowerbed = flowerbed + [0,1]
        for i in flowerbed:
            if i == 0 and start == 0:
                start = 1
                l += 1
            elif i == 0 and start == 1:
                l += 1
            elif i == 1 and start == 1:
                res += math.floor((l-1)/2)
                l = 0
                start = 0
            else:
                pass
        if res >= n:
            return True
        else:
            return False
        





```