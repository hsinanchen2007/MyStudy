### 解题思路
    可以认为是一个排列组合问题，n中最多包含2的数量为n//2,此时可以有组合公式
        C(all_count,two_count) => all_count ! / ((all_count - two_count)! * two_count!)
    n中最多包含2的数量为0,依次递推求和即可。

### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        two_count = n // 2
        sum_ = 0
        for i in range(two_count+1):
            all_count = n - i
            sum_ += math.factorial(all_count)//(math.factorial(all_count-i)*math.factorial(i))
        return sum_
        


```