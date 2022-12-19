### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0 for i in range(num_people)]
        n = 1
        while candies:
            for i in range(num_people):
                if candies > n:
                    candies -= n 
                    res[i] += n 
                    n += 1
                else:
                    res[i] += candies
                    candies -= candies
            
        return res
                
```