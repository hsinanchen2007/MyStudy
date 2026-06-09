## 思路：

质数就是除了 `1` 和本身找不到其他能除尽的数，思路请看题目的提示！

思路一：暴力法（超时）（大家可以学习一下 `for ... else` 的用法， 一般配合 `break` 使用）

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        res = 0
        for i in range(2, n):
            for j in range(2, i):
                if i % j == 0:
                    break
            else:
                #print(i)
                res += 1
        return res
```

思路二：优化暴力（超时），我们验证质数可以不需要小于它的数都验证

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        res = 0
        for i in range(2, n):
            for j in range(2, int(i ** 0.5) + 1):
                if i % j == 0:
                    break
            else:
                # print(i)
                res += 1
        return res
```

思路三：**厄拉多塞筛法**（好像能过）

![Sieve_of_Eratosthenes_animation.gif](https://pic.leetcode-cn.com/88746df426ec615529615ef5d9c7d10b9453cfe7c4e8bdb09219b8ba99abf9f1-Sieve_of_Eratosthenes_animation.gif)


```python
class Solution:
    def countPrimes(self, n: int) -> int:
        isPrimes = [1] * n
        res = 0
        for i in range(2, n):
            if isPrimes[i] == 1: res += 1
            j = i
            while i * j < n:
                isPrimes[i * j] = 0
                j += 1
        return res
```

思路四：综上一起优化（超过90%）

```python
class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2: return 0
        isPrimes = [1] * n
        isPrimes[0] = isPrimes[1] = 0
        for i in range(2, int(n ** 0.5) + 1):
            if isPrimes[i] == 1:
                isPrimes[i * i: n: i] = [0] * len(isPrimes[i * i: n: i])
        return sum(isPrimes)
```



