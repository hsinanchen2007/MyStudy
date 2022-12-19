### 解题思路
此处撰写解题思路
两个for 循环
第一次只看左边第二次只看右边，看右边的时候有个细节要注意  如果i-1  比 i值大的时候，要看这两个小朋友的当前的糖果数，如果已经符合要求的话就不需要再分配糖果了
### 代码

```python3
class Solution:
    def candy(self, ratings: List[int]) -> int:
        res = [1] * len(ratings)
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                res[i] = res[i - 1] + 1
        for i in range(len(ratings) - 1, 0, -1):
            if ratings[i - 1] > ratings[i] and res[i-1] <= res[i]:
                res[i - 1] = res[i] + 1
        return sum(res)
```