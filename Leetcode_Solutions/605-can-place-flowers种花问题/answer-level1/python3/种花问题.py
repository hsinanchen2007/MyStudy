### 解题思路
需要考虑是否有1，以及连续0的位置

### 代码

```python3
class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        ret = temp = flag = 0
        for i in flowerbed:
            if i == 0:
                temp += 1
            if i == 1:
                if flag == 0:
                    flag = 1
                    ret += temp // 2
                else:
                    ret += (temp - 1) // 2
                temp = 0
        ret += temp // 2
        if 1 not in flowerbed:
            ret = (temp + 1) // 2
        if ret >= n:
            return True
        else:
            return False
```