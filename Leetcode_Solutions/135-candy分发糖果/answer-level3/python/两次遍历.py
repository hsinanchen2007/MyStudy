### 解题思路
自左向右遍历，如果右边的比左边的大，就取res左边值+1，否则就是1
自右向左遍历，如果左边的比右边的大，就去res右边值+1和原来的值的最大值
### 代码

```python3
class Solution:
    def candy(self, ratings: List[int]) -> int:
        res = [1] * len(ratings)
        # 自左向右遍历，如果右边的比左边的大，就取res左边值+1，否则就是1
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i-1]:
                res[i] = res[i-1] + 1
        # 自右向左遍历，如果左边的比右边的大，就去res右边值+1和原来的值的最大值
        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i+1]:
                res[i] = max(res[i], res[i+1]+1)
        return sum(res)
```