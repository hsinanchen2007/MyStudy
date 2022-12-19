### 解题思路
如何用代码写故事

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        tangguo = 1
        xiaopengyou = 0
        dp = [0 for i in range(num_people)]
        while candies:
            if xiaopengyou >= num_people:
                xiaopengyou = 0
            if tangguo > candies:
                dp[xiaopengyou] +=  candies
                candies = 0
            else:
                dp[xiaopengyou] += tangguo
                candies -= tangguo
                tangguo += 1
                xiaopengyou += 1

        return dp
            

```