### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        count = 1
        lis=[0]*num_people
        while candies>0:
            for i in range(num_people):
                if candies > count:
                    lis[i] += count
                    candies -= count
                    count += 1
                else:
                    lis[i] += candies
                    candies=0         #不可换break
        return lis
```