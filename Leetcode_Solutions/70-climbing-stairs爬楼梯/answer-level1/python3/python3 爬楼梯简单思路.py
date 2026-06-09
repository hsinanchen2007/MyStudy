### 解题思路
用了一下高中的知识，一开始全部使用2层的方式上楼，每次减少1次2层的上楼方式直到全为每次只上一层。
计算方法就是排列组合，求出所有可能性即可。

### 代码

```python3
class Solution:
    def factorial(x):
        num = 1
        while(x > 0):
            num *= x
            x -= 1
        return num

    def climbStairs(self, n: int) -> int:
        double = int(n / 2)
        result = 0
        while(double >= 0):
            result += Solution.factorial(n-double)/(Solution.factorial(n-2*double) * Solution.factorial(double))
            double -= 1
        return int(result)

    

```