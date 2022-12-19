### 解题思路
初始队列元素均为0，
只要糖没发完，就对队列进行轮询

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0 for i in range(num_people)]
        many = 1
        while candies > 0:
            for i in range(num_people):
                if candies >= many:
                    candies -= many
                    ans[i] += many
                    many += 1
                else:
                    ans[i] += candies
                    candies = 0
                    break
        return ans
```