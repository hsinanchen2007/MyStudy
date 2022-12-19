### 解题思路
思路很明确，循环一遍数组，判断数组中每个元素的两倍数是否存在，关键点在0的判断上。
数组中如果只有一个零，用index使arr.lndex(n) != arr.index(2*n)，将这个零过滤掉即可。
但是数组存在两个零及以上时，无法使用index，因为index返回第一个零的索引值，得到的结果永远是False。

### 代码

```python3
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        for m,n in enumerate(arr):
            if 2*n in arr and m != arr.index(n*2):
                return True
        return False
```