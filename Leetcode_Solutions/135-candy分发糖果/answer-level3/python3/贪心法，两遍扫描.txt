
-   贪心法
-   左右扫描进行两遍更新

-   首先从左面开始扫描，保证每一个节点的值最小是1，并且如果左面的评分比当前的低，当前的值更新为左面节点糖果数加一
-   然后从右面开始向左扫描，保证如果当前节点的评分大于右面节点，当前节点的糖果数量也大于右面节点即可



```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        length = len(ratings)
        ans = [1] * length
        for i in range(1, length):
            if ratings[i] > ratings[i - 1]:
                ans[i] = ans[i - 1] + 1 

        for i in range(length - 2, -1, -1):
            if ratings[i] > ratings[i + 1] and ans[i] <= ans[i + 1]:
                ans[i] = ans[i + 1] + 1

        return sum(ans)
```


