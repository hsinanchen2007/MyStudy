### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        turns = []
        for i in range(1, candies):
            if (candies - i) >= 0:
                turns.append(i)
                candies -= i
            else:
                turns.append(candies)
                break
    
        res = [0] * num_people
        for i in range(len(turns)):
            res[i%num_people] += turns[i]

        return res
```