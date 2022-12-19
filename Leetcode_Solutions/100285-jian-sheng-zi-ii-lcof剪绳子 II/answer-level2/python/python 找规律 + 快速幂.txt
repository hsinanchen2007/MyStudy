### 解题思路

规律见上一题的题解

### 代码

```python
class Solution:
    def cuttingRope(self, n: int) -> int:
        def pow(a, b):
            if b == 0: return 1
            if b == 1: return a
            x = pow(a, b>>1)
            ans = x * x % 1000000007
            if b % 2 == 1:
                ans = ans * a % 1000000007
            return ans
        if n < 4:
            return n - 1
        if n % 3 == 0:   # 都剪成 3
            return pow(3, (n//3))
        if n % 3 == 1:   # 剪一个 4,剩下的都剪成 3 （或者剪两个 2，剩下的都剪成 3）
            return (pow(3, ((n-4)//3)) * 4) % 1000000007
        if n % 3 == 2:   # 剪一个 2,剩下的都剪成 3
            return (pow(3, ((n-2)//3)) * 2) % 1000000007
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)