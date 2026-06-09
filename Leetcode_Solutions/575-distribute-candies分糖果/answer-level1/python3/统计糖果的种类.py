### 解题思路
只要比较妹妹所得糖果的数量和糖果的种类大小即可，返回较小的那个。

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        if not candies:
            return

        d={}
        for c in candies:
            d[c]=d.get(c, 0)+1

        return min(len(candies)//2, len(d))
```