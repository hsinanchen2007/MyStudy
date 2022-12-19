
Let $f:\{0,1,\ldots,n-1\}\to\mathbb{Z}_{+}$ be the value function. $f(i)$ is the number of arithmetic slices that **must** end with $i$. For $i$, if the condition `A[i] - A[i-1] == A[i-1] - A[i-2]` holds, then `[A[i-2], A[i-1], A[i]]` can constitute an arithmetic slice. What's more, appending `A[i]` to any slice that ends with `A[i-1]` will again give us an arithmetic slice that ends with `A[i]`. Thus, we have

$f(i) = f(i - 1) + 1$.

The "1" in the equation refers to the slice `[A[i-2], A[i-1], A[i]]`. 



Python code is below. We initialize $f$ with $0$s. Note the simple fact that any arithmetic slice in `A` must have ending somewhere in the array. Each `f[i]` records the number of arithmetic slices that end with $i$, so `f[i]`s for different `i`s record different slices. Summing the values up gives us the total number of arithmetic slices.

```
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        f = [0] * len(A)
        for i in range(2, len(A)):
            if A[i] - A[i-1] == A[i-1] - A[i-2]:
                f[i] = 1 + f[i-1]
        return sum(f)
```
