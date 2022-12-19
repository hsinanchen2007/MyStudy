### 解题思路
1. 初始化每个小朋友的糖果数量为0
2. 统计发糖果的次数，每个小朋友每次得到的糖果数量 == 发糖次数*人数 + 编号（从0开始） + 1
3. 如果糖果不够数量，则将所有剩下的糖果分配给当前小朋友，循环结束

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        if candies == 0:
            return []
        candies_people = [0] * num_people
        flag = 0
        while candies!=0:
            for i in range(num_people):
                if candies >= (i + num_people * flag + 1):
                    candies -= i + num_people  * flag + 1
                    candies_people[i] += i + num_people  * flag + 1
                else:
                    candies_people[i] += candies 
                    candies -= candies
            flag += 1
        return candies_people 
                    
            
```