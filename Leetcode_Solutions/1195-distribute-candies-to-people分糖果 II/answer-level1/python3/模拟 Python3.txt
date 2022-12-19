**思路：**

直接模拟。开一个长度为`num_people`的数组，索引`i`从`0`开始遍历，第`i % num_people`个小朋友分得`i + 1`块糖，糖的总数相应减少`i + 1`。最后不足`i + 1`块糖都给最后一个小朋友。

**代码：**

```python
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        i = 0
        while candies > i:
            ans[i % num_people] += i + 1
            candies -= i + 1
            i += 1
        ans[i % num_people] += candies
        return ans
```