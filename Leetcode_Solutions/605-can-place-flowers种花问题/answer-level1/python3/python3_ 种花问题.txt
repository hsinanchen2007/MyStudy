```python
def canPlaceFlowers(flowerbed, n):
    N = len(flowerbed)
    for i in range(N):
        if n == 0:
            break
        if flowerbed[i] == 0:
            # 如果是第一个元素, 则需要判断两种情况:
            # 1. 只有一朵花
            # 2. 后一朵花为0
            if i == 0:
                if N == 1 or flowerbed[i + 1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            # 如果是最后一个元素, 则判断前一个元素是否为0
            elif i == N - 1:
                if flowerbed[i - 1] == 0:
                    flowerbed[i] = 1
                    n -= 1
            # 否则是中间元素, 则判断前后是否等于0
            elif flowerbed[i - 1] == 0 and flowerbed[i + 1] == 0:
                flowerbed[i] = 1
                n -= 1
    return n == 0

print(canPlaceFlowers([1,0,0,0,1], 1))
print(canPlaceFlowers([1,0,0,0,1], 2))
```