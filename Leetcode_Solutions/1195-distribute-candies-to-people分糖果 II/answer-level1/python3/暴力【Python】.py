### 思路

**暴力**

```
直接暴力。有糖就一直分下去，直到没有糖为止。
```

**时间复杂度:** O(max(sqrt(G), N))，G 为糖果数量，N 为人数。
**空间复杂度:** O(1)

##### Python3代码

```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0] * num_people
        step = 0
        while candies > 0:
            res[step % num_people] += min(candies, step + 1)
            step += 1  # next person
            candies -= step  # the remaining candies
        return res
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/1103-Distribute-Candies-to-People/1103.py)