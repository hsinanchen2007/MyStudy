### 解题思路
贪心
遍历连续3个0中间位置即可插花
注意处理边界的方法，亦可两端补零

### 代码

```python3
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
                count += 1
                if count == n:
                    return True
                flowerbed[i] = 1
        return count >= n
```