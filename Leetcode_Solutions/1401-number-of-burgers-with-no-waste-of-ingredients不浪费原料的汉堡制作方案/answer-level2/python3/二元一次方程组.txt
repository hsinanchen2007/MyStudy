### 解题思路
二元一次方程组求整数解

### 代码

```python3
class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        if tomatoSlices == 0 and cheeseSlices == 0:
            return [0,0]
        # 这个感觉就是弄个二元一次方程组求解
        big_num = (tomatoSlices- 2*cheeseSlices)/2
        res = []
        if big_num == int(big_num):
            res.append(int(big_num))
            small_num = cheeseSlices-big_num
            res.append(int(small_num))
            if big_num<0 or small_num<0:
                return []
            return res
        else:
            return []


```