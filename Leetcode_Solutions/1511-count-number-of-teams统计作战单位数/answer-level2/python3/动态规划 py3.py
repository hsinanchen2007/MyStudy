### 代码

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        ans = 0
        lenth = len(rating)
        up = [1] * lenth
        down = [1] * lenth
        dic = {i:v for i, v in enumerate(rating)}
        # print(dic)
        for i in range(1, lenth):
            for j in range(i):
                # up
                if dic[i] > dic[j]:
                    up[i] += 1
                    if up[j] > 1:
                        ans += up[j]+2-3
                # down
                else:
                    down[i] += 1
                    if down[j] > 1:
                        ans += down[j] + 2 -3
        return ans
```