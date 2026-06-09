## 方案1

直接递归，重复计算，复杂度爆炸。

```
    def fib(self, N: int) -> int:
        return N if N == 0 or N == 1 else self.fib(N-1) + self.fib(N-2)
```

## 方案2

递归，使用functools里的缓存，复杂度n。

```
    from functools import lru_cache
    @lru_cache()
    def fib(self, N: int) -> int:
        return N if N == 0 or N == 1 else self.fib(N-1) + self.fib(N-2)
```

## 方案3

递归，自己实现缓存，复杂度n。

```
    cache = {0:0, 1:1}
    def fib(self, N: int) -> int:
        if N not in Solution.cache:
            Solution.cache[N] = self.fib(N-1) + self.fib(N-2)
        return Solution.cache[N]
```

## 方案四

使用逐渐增长的list递推，复杂度n，使用额外空间n(但是低于前面的方案)。

```
    def fib(self, N: int) -> int:
        cache = [0, 1]
        for i in range(N-1):
            cache.append(cache[-1] + cache[-2])
        return cache[N]
```

## 方案五

使用定长2的list递推，复杂度n，使用固定的额外空间。

```
    def fib(self, N: int) -> int:
        cache = [0, 1]
        for i in range(N-1):
            cache[i%2] = cache[0] + cache[1]
        return cache[N%2]
```

## 方案六

使用矩阵计算，配合矩阵快速幂算法，时间复杂度logn(若不使用快速幂则依然是n)。

```
    def fib(self, N: int) -> int:
        def matrixpow(matrix, n):
            def matrixmul(mA, mB):
                def vectormul(vA, vB):
                    return [i*j for i,j in zip(vA, vB)]
                ra, ca, rb, cb = len(mA), len(mA[0]), len(mB), len(mB[0])
                if ca != rb:
                    raise Exception("matrix not match")
                return [[sum(vectormul(mA[i],[i[j] for i in mB])) for j in range(cb)] for i in range(ra)]
            
            res = matrix
            n -= 1
            while n:
                if n&1:
                    res = matrixmul(res, matrix)
                matrix = matrixmul(matrix, matrix)
                n >>= 1
            return res

        return N if N == 0 or N == 1 else matrixpow([[1,1],[1,0]],N-1)[0][0]
```