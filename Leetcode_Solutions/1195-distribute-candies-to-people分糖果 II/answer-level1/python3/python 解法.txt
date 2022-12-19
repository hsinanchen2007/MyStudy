### 解题思路
一开始是用for循环来解决下标的问题，后来参考了用取余的方式写的，这样就简洁多了

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0] * num_people
        count = 1
        index = 0
        while candies > 0:
            ans[index % num_people] += min(count, candies)
            candies -= count
            index += 1
            count += 1
        return ans
             
```