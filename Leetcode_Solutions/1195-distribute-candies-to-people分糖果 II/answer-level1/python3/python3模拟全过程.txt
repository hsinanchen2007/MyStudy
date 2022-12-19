### 解题思路
用一个列表和不断累加的变量模拟全过程即可

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        res=[0]*num_people
        i=0
        while candies:
            if candies>=i+1:
                res[i%num_people]+=i+1
                candies-=i+1
            else:
                res[i%num_people]+=candies
                break
            i+=1
        return res
```