### 解题思路
尝试了等差数列，总有细节没写明白。我选择暴力，代码清爽易读。下次做把优化方法补上

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 0
        j = 1
        while candies > 0:
            ans[i % num_people] += min(j, candies)
            # print(ans)
            candies -= j
            j += 1
            i += 1
        return ans

            



        
```