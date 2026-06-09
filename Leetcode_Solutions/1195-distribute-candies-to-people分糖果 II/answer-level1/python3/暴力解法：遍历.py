### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res = [0 for _ in range(num_people)]
        num = 1
        while candies>num:
            who = (num-1)%num_people
            res[who] += num
            candies -= num
            num +=1
        who = (num-1)%num_people
        res[who]+=candies
        return res
            

```