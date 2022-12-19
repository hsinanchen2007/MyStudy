两端各补两个位置[1,0]和[0,1]，计算所有连续零个数减一再整除二的结果之和，与N作比较
```
class Solution:

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        placed_idx_list = []
        flowerbed = [1, 0 ] + flowerbed + [0, 1]
        for i in range(len(flowerbed)):
            if flowerbed[i] == 1:
                placed_idx_list.append(i)
        for j in range(len(placed_idx_list) - 1):
            count += (placed_idx_list[j + 1] - placed_idx_list[j] - 2)>>1
            if count >= n:
                return True
                break
        return False

```
