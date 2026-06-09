### 代码

```python3
class Solution:
    def cuttingRope(self, n: int) -> int:
        # # 解法 1： 动态规划
        # if n < 2:
        #     return 0
        # if n == 2:
        #     return 1
        # if n == 3:
        #     return 2

        # products = [0, 1, 2, 3]
        # for i in range(4, n+1):
        #     max_val = 0
        #     for j in range(1, (i//2)+1):
        #         product = products[j] * products[i-j]
        #         max_val = max(max_val, product)
        #     products.append(max_val)
        # return products[n] % 1000000007

        # 解法 2： 贪婪算法
        if n < 2:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2

        times_of_3 = n // 3
        if n % 3 == 1:
            times_of_3 -= 1

        times_of_2 = (n - times_of_3 * 3) //2
        return (pow(3, times_of_3) * pow(2, times_of_2)) % 1000000007
```