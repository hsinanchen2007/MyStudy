### 解题思路
直接用排列组合的数学知识解答!
N choose K
N 是 单步和双步的和, 即一共爬几下.
K 是单步或者双步都行!

### 代码

```python3
import math

class Solution:
    def climbStairs(self, n: int) -> int:
        double_num = 0
        double_num_max = n // 2  # 最多爬几个双步
        total = 0
        for i in range(0, double_num_max + 1): # range函数是左闭右开区间
            single_num = n - 2 * i
            N = single_num + i
            temp =  math.factorial(N) // ( math.factorial(N - i) * math.factorial(i) )
            total += temp
        return total

```