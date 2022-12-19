### 解题思路
遍历

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        nums = [0]*num_people
        if num_people == 0 or candies == 0:
            return
        if num_people == 1:
            nums[0] = candies
            return num_people
        
        count = 0
        while candies:
            for i in range(num_people):
                if candies >= count*num_people + i +1:
                    nums[i] += count*num_people + i + 1
                    candies -= count*num_people + i + 1
                else:
                    nums[i] += candies
                    candies = 0
            count += 1
        return nums
```