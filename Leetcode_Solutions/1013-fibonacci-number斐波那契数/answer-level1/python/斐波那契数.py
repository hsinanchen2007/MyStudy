####  方法一：递归
使用递归计算给定整数的斐波那契数。

![在这里插入图片描述](https://pic.leetcode-cn.com/5575fb4ab0df264cba3a47172961895aaa7a52072b8241b8ea6d3a6b7f084c60-file_1577091644006){:width=530}


上图表示了 `fib(5)` 计算过程的递归树

**算法：**
- 检查整数 `N`，如果 `N` 小于等于 `1`，则返回 `N`。
- 否则，通过递归关系：$F_{n} = F_{n-1} + F_{n-2}$ 调用自身。
- 直到所有计算返回结果得到答案。

```java [solution1-Java]
public class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        return fib(N-1) + fib(N-2);
    }
}
```

```python [solution1-Python]
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        return self.fib(N-1) + self.fib(N-2)
```

```go[solution1-Go]
func fib(N int) int {
    if N <= 1 {
        return N
    }
    return fib(N-1) + fib(N-2)
}
```

**复杂度分析**

* 时间复杂度：$O(2^N)$。这是计算斐波那契数最慢的方法。因为它需要指数的时间。
* 空间复杂度：$O(N)$，在堆栈中我们需要与 `N` 成正比的空间大小。该堆栈跟踪 `fib(N)` 的函数调用，随着堆栈的不断增长如果没有足够的内存则会导致 `StackOverflowError`。


####  方法二：记忆化自底向上的方法
自底向上通过迭代计算斐波那契数的子问题并存储已计算的值，通过已计算的值进行计算。减少递归带来的重复计算。

**算法：**
- 如果 `N` 小于等于 `1`，则返回 `N`。
- 迭代 `N`，将计算出的答案存储在数组中。
- 使用数组前面的两个斐波那契数计算当前的斐波那契数。
- 知道我们计算到 `N`，则返回它的斐波那契数。

```java [solution2-Java]
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        return memoize(N);
    }

    public int memoize(int N) {
      int[] cache = new int[N + 1];
      cache[1] = 1;

      for (int i = 2; i <= N; i++) {
          cache[i] = cache[i-1] + cache[i-2];
      }
      return cache[N];
    }
}
```
```python [solution2-Python]
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        return self.memoize(N)

    def memoize(self, N: int) -> {}:
        cache = {0: 0, 1: 1}

        # Since range is exclusive and we want to include N, we need to put N+1.
        for i in range(2, N+1):
            cache[i] = cache[i-1] + cache[i-2]

        return cache[N]
```

```go [solution2-Go]
func fib(N int) int {
    if N <= 1 {
        return N
    }
    return memoize(N)
}

func memoize(N int) int {
    cache := map[int]int{0: 0, 1: 1}

    for i := 2; i <= N; i++ {
        cache[i] = cache[i-1] + cache[i-2]
    }
    return cache[N]
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。
* 空间复杂度：$O(N)$，使用了空间大小为 `N` 的数组。


####  方法三：记忆化自顶向下的方法
我们先计算存储子问题的答案，然后利用子问题的答案计算当前斐波那契数的答案。我们将递归计算，但是通过记忆化不重复计算已计算的值。

**算法：**
- 如果 `N <= 1`，则返回 `N`。
- 调用和返回 `memoize(N)`。
- 如果 `N` 对应的斐波那契数存在，则返回。
- 否则将计算 `N` 对应的斐波那契数为 `memoize(N-1) + memoize(N-2)`。

```java [solution3-Java]
class Solution {
    private Integer[] cache = new Integer[31];

    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        cache[0] = 0;
        cache[1] = 1;
        return memoize(N);
    }

    public int memoize(int N) {
      if (cache[N] != null) {
          return cache[N];
      }
      cache[N] = memoize(N-1) + memoize(N-2);
      return memoize(N);
    }
}
```

```python [solution3-Python]
class Solution:
    def fib(self, N: int) -> int:
        if N <= 1:
            return N
        self.cache = {0: 0, 1: 1}
        return self.memoize(N)

    def memoize(self, N: int) -> {}:
        if N in self.cache.keys():
            return self.cache[N]
        self.cache[N] = self.memoize(N-1) + self.memoize(N-2)
        return self.memoize(N)
```

```go [solution3-Go]
var cache = map[int]int{0: 0, 1: 1}

func fib(N int) int {
    if N <= 1 {
        return N
    }
    return memoize(N)
}

func memoize(N int) int {
    if _, ok := cache[N]; ok {
        return cache[N]
    }
    cache[N] = memoize(N-1) + memoize(N-2)
    return memoize(N)
}
```


**复杂度分析**

* 时间复杂度：$O(N)$。
* 空间复杂度：$O(N)$，内存中使用的堆栈大小。


####  方法四：自底向上进行迭代
**算法：**
- 若 `N <= 1`，则返回 `N`。
- 若 `N == 2`，则返回 `fib(2-1) + fib(2-2) = 1`。
- 使用迭代的方法，我们至少需要三个变量存储 `fib(N)`, `fib(N-1)` 和 `fib(N-2)`。
- 预置初始值：
	- `current = 0`。
	- `prev1 = 1`，代表 `fib(N-1)`。
	- `prev2 = 1`，代表 `fib(N-2)`
- 我们从 `3` 计算到 `N`；`0`，`1`，`2`对应的斐波那契数是预先计算。
- 设置 `current = fib(N-1) + fib(N-2)`，因为 `current` 代表的是当前计算的斐波那契数。
- 设置 `prev2 = fib(N-1)`。
- 设置 `prev1 = current`。
- 当我们到达 `N+1`，将退出循环并返回 `current`。

```java [solution4-Java]
class Solution {
    public int fib(int N) {
        if (N <= 1) {
            return N;
        }
        if (N == 2) {
            return 1;
        }

        int current = 0;
        int prev1 = 1;
        int prev2 = 1;

        for (int i = 3; i <= N; i++) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
}
```
```python [solution4-Python]
class Solution:
    def fib(self, N: int) -> int:
        if (N <= 1):
            return N
        if (N == 2):
            return 1

        current = 0
        prev1 = 1
        prev2 = 1

        # Since range is exclusive and we want to include N, we need to put N+1.
        for i in range(3, N+1):
            current = prev1 + prev2
            prev2 = prev1
            prev1 = current
        return current
```
```go [solution4-Go]
func fib(N int) int {
    if N <= 1 {
        return N
    }
    if N == 2 {
        return 1
    }

    current := 0
    prev1 := 1
    prev2 := 1

    for i := 3; i <= N; i++ {
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current
    }
    return current
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。
* 空间复杂度：$O(1)$，仅仅使用了 `current`，`prev1`，`prev2`。


####  方法五：矩阵求幂
斐波那契数列矩阵方程：

![在这里插入图片描述](https://pic.leetcode-cn.com/09fd107ad5ce57b564aaae069bacd1b04fbb5033197d99305e3a45764bf07fee.png)

**算法：**
- 若 `N` 小于等一 `1`，则返回 `N`。
- 使用递归函数 `matrixPower` 计算给定矩阵 `A` 的幂。幂为 `N-1`，其中 `N` 是第 `N` 个 斐波那契数。
- `matrixPower` 函数将对 `N/2` 个斐波那契数进行操作。
- 在 `matrixPower` 中，调用 `multiply` 函数将两个矩阵相乘。
- 完成计算后，返回 `A[0][0]` 得到第 `N` 个斐波那契数。
```java [solution5-Java]
class Solution {
    int fib(int N) {
        if (N <= 1) {
          return N;
        }
        int[][] A = new int[][]{{1, 1}, {1, 0}};
        matrixPower(A, N-1);

        return A[0][0];
    }

    void matrixPower(int[][] A, int N) {
        if (N <= 1) {
          return;
        }
        matrixPower(A, N/2);
        multiply(A, A);

        int[][] B = new int[][]{{1, 1}, {1, 0}};
        if (N%2 != 0) {
            multiply(A, B);
        }
    }

    void multiply(int[][] A, int[][] B) {
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
}
```

```python [solution5-Python]
class Solution:
    def fib(self, N: int) -> int:
        if (N <= 1):
            return N

        A = [[1, 1], [1, 0]]
        self.matrix_power(A, N-1)

        return A[0][0]

    def matrix_power(self, A: list, N: int):
        if (N <= 1):
            return A

        self.matrix_power(A, N//2)
        self.multiply(A, A)
        B = [[1, 1], [1, 0]]

        if (N%2 != 0):
            self.multiply(A, B)

    def multiply(self, A: list, B: list):
        x = A[0][0] * B[0][0] + A[0][1] * B[1][0]
        y = A[0][0] * B[0][1] + A[0][1] * B[1][1]
        z = A[1][0] * B[0][0] + A[1][1] * B[1][0]
        w = A[1][0] * B[0][1] + A[1][1] * B[1][1]

        A[0][0] = x
        A[0][1] = y
        A[1][0] = z
        A[1][1] = w
```

```go [solution5-Go]
func fib(N int) int {
    if N <= 1 {
        return N
    }
    var A = [2][2]int{
        {1,1},
        {1,0},
    }
    A = matrixPower(A, N-1)
    return A[0][0]
}

func matrixPower(A [2][2]int, N int) [2][2]int {
    if N <= 1 {
        return A
    }
    A = matrixPower(A, N/2)
    A = multiply(A, A)

    var B = [2][2]int{
        {1,1},
        {1,0},
    }
    if N%2 != 0 {
        A = multiply(A, B)
    }

    return A
}

func multiply(A [2][2]int, B [2][2]int) [2][2]int {
    x := A[0][0] * B[0][0] + A[0][1] * B[1][0];
    y := A[0][0] * B[0][1] + A[0][1] * B[1][1];
    z := A[1][0] * B[0][0] + A[1][1] * B[1][0];
    w := A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;

    return A
}
```

**复杂度分析**

* 时间复杂度：$O(\log N)$。
* 空间复杂度：$O(\log N)$，`matrixPower` 函数递归时堆栈使用的空间。 


####  方法六：公式法
- 使用黄金分割比：$\varphi = \frac{1 + \sqrt{5}}{2} \approx 1.6180339887....$，Binet 公式 ：

![在这里插入图片描述](https://pic.leetcode-cn.com/d5e05b3f46910d4bf79d3b235e5a3d7803b63bce092c6c20a53c16d228e33113.png)

- 这里有一个[链接](http://demonstrations.wolfram.com/GeneralizedFibonacciSequenceAndTheGoldenRatio/)，可以进一步了解斐波那契序列和黄金分割比之间的关系。
- 我们可以只能用常数时间和常数空间得到斐波那契数。

**算法：**

使用黄金分割率计算第 `N` 个斐波那契数。

```java [solution6-Java]
class Solution {
    public int fib(int N) {
        double goldenRatio = (1 + Math.sqrt(5)) / 2;
        return (int)Math.round(Math.pow(goldenRatio, N)/ Math.sqrt(5));
    }
}
```

```python [solution6-Python]
# Contributed by LeetCode user mereck.
class Solution:
  def fib(self, N):
  	golden_ratio = (1 + 5 ** 0.5) / 2
  	return int((golden_ratio ** N + 1) / 5 ** 0.5)
```

```go [solution6-Go]
func fib(N int) int {
    var goldenRatio float64 = float64((1 + math.Sqrt(5)) / 2);
    return int(math.Round(math.Pow(goldenRatio, float64(N)) / math.Sqrt(5)));
}
```

**复杂度分析**

* 时间复杂度：$O(1)$。常数的时间复杂度，因为我们是基于 `Binet` 公式进行计算，没有使用循环或递归。
* 空间复杂度：$O(1)$，存储黄金分割率所使用的空间。