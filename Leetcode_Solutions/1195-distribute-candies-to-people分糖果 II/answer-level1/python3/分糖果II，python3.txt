### 解题思路
分到完为止

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0 for _  in range(num_people)]
        temp = 1
        while candies > 0:
            res[(temp-1)%num_people] += temp
            candies -= temp
            temp += 1 
            if candies < temp:
                res[(temp-1)%num_people] += candies
                break
        return res
```