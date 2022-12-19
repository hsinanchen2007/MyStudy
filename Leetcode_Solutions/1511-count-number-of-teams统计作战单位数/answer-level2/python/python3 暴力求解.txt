### 解题思路
暴力求解

### 代码

```python3
class Solution:
    def numTeams(self, rating: List[int]) -> int:
        count = 0
        for i in range(len(rating)):
            for j in range(i, len(rating)):
                if rating[j] > rating[i]:
                    for x in range(j, len(rating)):
                        if rating[x] > rating[j]:
                            count += 1
                elif rating[j] < rating[i]:
                    for y in range(j, len(rating)):
                        if rating[y] < rating[j]:
                            count += 1
        return count
```