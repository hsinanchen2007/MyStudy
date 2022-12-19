计数连续的0的个数，需要处理好两端（通过添加10和01）



```
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0: return True
        flowerbed = [1, 0] + flowerbed + [0, 1]
        count, res = 0, 0
        for flower in flowerbed:
            if flower == 0:
                count += 1
            elif count > 0:
                    res += (count - 1) // 2                
                    if res >= n: return True
                    count = 0
        return False
```
