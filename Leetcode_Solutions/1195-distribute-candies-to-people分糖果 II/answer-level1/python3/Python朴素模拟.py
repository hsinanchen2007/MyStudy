### 解题思路
模拟分配过程，比较容易实现。

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0 for _ in range(num_people)]
        distribution, i = 1, 0      # 当前分配数量，第i个小炮友
        while candies:
            if candies - distribution >= 0:
                res[i] += distribution
                candies -= distribution
            else:
                res[i] += candies
                candies = 0
            distribution += 1
            i = (i + 1) % num_people
        return res

```