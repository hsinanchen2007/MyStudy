### 解题思路
最简单的思路，顺着题目给的步骤走

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        n = 1   # 当前要分配的糖果数
        k = 0   # 当前小朋友序号
        while candies:
            if candies < n:
                ans[k] += candies
                break
            candies -= n
            ans[k] += n
            n += 1
            k = (k+1) % num_people
        return ans

```