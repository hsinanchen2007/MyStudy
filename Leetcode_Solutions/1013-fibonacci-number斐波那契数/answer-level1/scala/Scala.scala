### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def fib(N: Int): Int = {
        var res = 0
    if (N < 2) return N
    if (N > 1) {
      res = fib(N - 1) + fib(N - 2)
    }
    res
    }
}
```