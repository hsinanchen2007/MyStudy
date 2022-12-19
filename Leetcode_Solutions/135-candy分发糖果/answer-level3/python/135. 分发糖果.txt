### 代码

```python3
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        if n < 2:
            return n
        if n == 2:
            if ratings[0] == ratings[1]:
                return n
            else:
                return n + 1
        num = [1] * n # 初始化，每人分得一颗糖
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]: # 从左向右遍历， 右侧分高时拿的糖数量+1
                num[i] = num[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]: # 从右向左遍历， 左侧分高时拿的糖数量+1
                num[i] = max(num[i + 1] + 1, num[i]) # 取两次遍历后的最大值，以符合题意
        return sum(num) # 返回糖果数量


```