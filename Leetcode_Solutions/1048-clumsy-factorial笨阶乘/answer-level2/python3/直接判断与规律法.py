- 直接判断即可，每4个看成一部分
- 除了第一部分，其他的都是同样的模式，前面乘除部分减去，后面加上一个数



```python
class Solution:
    def clumsy(self, N: int) -> int:
        temp = [0, 1, 2, 6, 7]
        if N <= 4:
            return temp[N]
        res = N * (N - 1) // (N - 2) + N - 3
        N -= 4
        while N > 0:
            if N >= 4:
                res = res - N * (N - 1) // (N - 2) + N - 3
                N -= 4
            else:
                res -= temp[N]
                break

        return res
```



- 找规律法

通过观察可以发现，除了`4*3/2=6`这个以外，其他组合得到值都是最大的数加一，

```
7*6/5 = 8
100*99/98 = 101
```

因此，根据这个规律，可以直接得到乘除部分结果

```python
class Solution:
    def clumsy(self, N: int) -> int:
        temp = [0, 1, 2, 6, 7]
        if N <= 4:
            return temp[N]
        res = N + 1 + N - 3
        N -= 4
        while N > 0:
            if N > 4:
                res -= 4
                N -= 4
            elif N == 4:
                res -= 5
                break
            else:
                res -= temp[N]
                break
        return res
```

优化计算：

```python
class Solution:
    def clumsy(self, N: int) -> int:
        temp = [0, 1, 2, 6, 7]
        if N <= 4:
            return temp[N]
        res = N + 1 + N - 3
        N -= 4

        four_times = N // 4
        remainder = N % 4

        if remainder:
            return res + -4 * four_times - temp[remainder]
        else:
            return res + -4 * (four_times - 1) - 5
```


