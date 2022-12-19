### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ret = [0]*num_people
        oret = 0
        while candies:
            for i in range(num_people):
                oret+=1
                if candies <= oret:
                    ret[i]+=candies
                    return ret
                ret[i]+=oret
                candies -= oret
                
                
            
            
```