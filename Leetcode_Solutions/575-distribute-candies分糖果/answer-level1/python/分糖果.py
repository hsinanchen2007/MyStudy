### 解题思路
先排序，然后其实就是比较种类和总数的一半，选择小的值返回

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        sum_ = len(candies)
        candies.sort()
        kind = 1
        for i in range(1, sum_):
            if candies[i] != candies[i - 1]:
                kind += 1
        return min(kind, sum_ // 2)
```