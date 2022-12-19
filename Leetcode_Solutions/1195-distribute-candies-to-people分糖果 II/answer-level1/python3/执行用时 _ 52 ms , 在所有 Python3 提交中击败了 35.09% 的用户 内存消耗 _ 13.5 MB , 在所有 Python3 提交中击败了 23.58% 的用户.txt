### 解题思路
分发次数、剩余糖果数、当前需要发放的糖果数分别创建变量，每轮将当前应发的糖果数与剩余糖果数作比较，如果剩余糖果充足，就按照应发放数量在对应位置累加，否则，就按照剩余糖果数量在对应位置累加。

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        rest_candies = candies
        tmp_candies = 0
        times = 1
        result = [0] * num_people
        while rest_candies:
            for i in range(num_people):
                tmp_candies = i + times 
                if rest_candies >= tmp_candies:
                    result[i] += tmp_candies
                    rest_candies -= tmp_candies
                else:
                    result[i] += rest_candies
                    rest_candies = 0
            times += num_people
        return result
            
                 

```