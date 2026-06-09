由题可知：m个1(k) = n(10)

k^m + k^(m-1) + ... + k + 1 = n
等比数列求和： (k^(m+1) - 1) / (k - 1) = n

所以 m = logk((n(k-1)+1)/k)
当k = 2时，m有最大值log2((n+1)/2)

所以m的范围为[2, log2((n+1)/2)]，通过遍历m求k，验证k可得最终结果。

由k^m + k^(m-1) + ... + k + 1 = n (m > 1)，可知：
k^m < n < (k+1)^m
k < n^(1/m) < k+1
n^(1/m)-1 < k < n^(1/m)

所以，估算k = int(n^(1/m))
当k符合 k^(m+1) - 1 == n*(k-1), 则k为解

k随m的增大而减小，m从大到小遍历时，第一次得出的k即为最小值，当遍历结束仍无法得出k，则k=n-1

python3代码如下：
```python3
class Solution:
    def smallestGoodBase(self, n: str) -> str:
        n = int(n)
        k = 0
        m = math.log((n+1)/2, 2)
        i = int(m)
        while i >= 2:
            a = n ** (1 / i)
            a = int(a)
            if (a ** (i + 1) == n * (a - 1) + 1):
                k = a
                break
            i -= 1
        if (k == 0): k = n - 1
        return str(k)
```

顺便一提，因为js固有的bug，所以js不适合用来解这题
```javascript
1000000000000000000 - 1 // 1000000000000000000
parseInt("16035713712910627") // 16035713712910628
16035713712910628 - 1 // 16035713712910628
```


