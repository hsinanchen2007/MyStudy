### 解题思路
while循环，求模

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0]*num_people
        i = 0
        j = 1
        while candies>0:
            candi = min(j, candies)
            ans[i%num_people] += candi  
            j += 1
            i += 1
            candies -= candi
        return ans


```