### 组合数求解
#### 算法
1. 两个台阶的个数x
2. 1个台阶的格式n-2x
3. 总的步数n-2x+x=n-x
4. 组合数C(n-2x,n-x)

```python []
class Solution:
    def climbStairs(self, n: int) -> int:
        def combination(m:int, n:int) -> int:
            n_factorial = 1
            for i in range(1, n + 1):
                n_factorial = n_factorial * i
            m_factorial = 1
            for i in range(1, m + 1):
                m_factorial = m_factorial * i
            n_m_factorial = 1
            for i in range(1, n - m + 1):
                n_m_factorial = n_m_factorial * i
            return int(n_factorial / (m_factorial * n_m_factorial))

        # 两个台阶的个数x
        # 1个台阶的格式n-2x
        # 总的步数n-2x+x=n-x
        # 组合数C(n-2x,n-x)
        ans = 0
        x = 0
        while x * 2 <= n:
            temp = combination(n - 2 * x, n - x)
            ans = ans + temp
            x = x + 1
        return ans
```
#### 复杂度分析
- 时间复杂度：O(n^2)，包含了解组合数的时间
- 空间复杂度：O(2)
