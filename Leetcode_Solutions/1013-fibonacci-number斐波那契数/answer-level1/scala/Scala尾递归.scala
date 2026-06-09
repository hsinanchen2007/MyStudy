使用了尾递归，会被转为循环，不用担心栈溢出

思路：
迭代：下一轮的a用于保存上一轮的结果(即上一轮的`b`)，下一轮的b用来进行两轮结果求和(上轮的a是上上轮的结果，上轮的b即是上轮的结果，即`a+b`为上两轮的结果之和). `(a1, b1) = (b0, a0 + b0) `
初值：使得初始为 `a = 0, b = 1`. 原因：斐波那契数列为1, 1, 2, 3, ...,  应使得(a, b) 为 (0, 1), (1, 1), (1, 2), (2, 3)...
递归终止条件：当递归到k == 1时就可以输出结果b了


ps: 可以在IDE里fib和run之间加上`@annotation.tailrec`注解测试是否正确的使用了尾递归

scala写，就是赏心悦目


```scala
object Solution {
    def fib(N: Int): Int = {
        def run(k: Int, a: Int, b: Int): Int = 
            if (k == 0) 0
            else if (k == 1) b
            else run(k-1, b, a+b)
        
       run(N, 0, 1)
    }
}
```
