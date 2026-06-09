### 解题思路
递归循环的题，知道两个初始条件，跳上一阶台阶和两阶台阶可以的方法数，计算后面的。
f(n) = f(n-1)+f(n-2)，跳第n个台阶，即先跳一阶，再跳n-1阶，或者先跳2阶，再跳n-2阶，
这两种情况的方法和。
其实这个题就是斐波那切数列，一模一样
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 0:
            return 0
        result = [1,2]  # 初始值，跳一个,两个台阶的方法数目
        for i in range(2, n):
            result.append(result[i-2]+result[i-1])
        return result[n-1]


```