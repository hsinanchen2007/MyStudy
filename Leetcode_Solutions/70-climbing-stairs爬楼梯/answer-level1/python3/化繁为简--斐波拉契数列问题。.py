### 解题思路
1. 暴力破解是否可行？  不可。
2. 化繁为简。找最近重复子问题。 可以。
3. 数学归纳法：
    第3级台阶如何上？其实就是第1级走2步，第2级走1步，最后一步不一样，能保证不重复计算。因此，第4级台阶就是从第2级走2步，第三级走1步。 
    最后可得，f(n) = f(n-2) + f(n-1).   # 其中f(n)表示n级台阶走上去的种类数。也就是一个斐波拉契数列问题。

### 代码

```python
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n <= 2:
            return n
        # 只保存最后3个值，然后不断往前累加即可
        f1, f2, f3 = 1, 2, 3
        for i in range(3, n+1):
            f3 = f1 + f2
            f1 = f2
            f2 = f3
        return f3
```