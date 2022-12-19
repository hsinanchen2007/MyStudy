### 解题思路
[dongzengjie的回答](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/comments/239399)对我的启发很大，但他没有说明等式成立的原因，我这里简单记录下我的理解。

按照斐波拉契数的定义，我们可以得出以下等式：
`fib（n） = fib(n-1) + fib(n-2)`
当然可以直接用这个等式来求解：
```
fun fib(n: Int): Int {
    return if (n <= 1) {
        n
    } else {
        fib(n - 1) + fib(n - 2)
    }
}
```
逻辑简单明了，但是由于每次计算都需要递归计算之前的两个斐波拉契数，越往后计算量越大，性能、耗时呈指数级上升。

于是尝试模拟我们人工计算的方式，从fib(0)开始，按照斐波拉契数定义依次计算fib(0~n)。
设fib(n-1)为n1，fib(n-2)为n2，则有：
```
fib(n) = n1 + n2
fib(n-1) = fib(n) - n1
```
我们用n1保存n对应的斐波拉契数，用n2保存n-1对应的斐波拉契数。于是得到了下面的代码：

### 代码

```kotlin
class Solution {
fun fib(n: Int): Int {
    var n1 = 1 //fib(n-1)
    var n2 = 0 //fib(n-2)
    return if (n <= 1) {
        n
    } else {
        for (x in 2..n) {
            n1 = (n1 + n2)
            n2 = (n1 - n2) % 1000000007
            n1 %= 1000000007
        }
        n1
    }
}
}
```