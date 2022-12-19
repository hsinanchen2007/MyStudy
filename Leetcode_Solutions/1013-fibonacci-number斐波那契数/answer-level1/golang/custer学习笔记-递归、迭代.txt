### 解题思路 - 递归方法

根据斐波那契数列定义可以非常简单写出递归方法

### 代码

```golang
// 递归  Time: O(2^n), Space: O(n)
func fib(N int) int {
   if N <= 0 { // 先处理最基本情况
      return 0
   }
   if N == 1 {
      return 1
   }
   return fib(N-1) + fib(N-2) // 其他情况就计算前两项的和
}
```

### 解题思路 - 迭代方法
递归方法的时间复杂度之所以这么大，是因为这个过程中有很多的重复计算。

可以使用一个辅助数组，自底向上的计算斐波那契数列的每一项，这样一来就可以避免重复计算了。

这种方法只需要一个个的计算前n个斐波那契数，因此时间复杂度是O(n),使用了一个辅助数组，因此空间复杂度是O(n)

### 代码

```golang
// 迭代 Time: O(n), Space: O(n)
func fib(N int) int {
   if N <= 0 { // 先处理最基本情况
      return 0
   }
   if N == 1 {
      return 1
   }
   d := make([]int, N+1) // 定义辅助数组，
   d[0] = 0              // 并把前两项定义为0和1
   d[1] = 1
   // 接下来计算从第2到第n个的斐波那契数
   for i := 2; i <= N; i++ {
      d[i] = d[i-1] + d[i-2]
   }
   return d[N] // 最后返回d[n]即可
}
```

### 解题思路 - 降低空间复杂度
由于斐波那契数列每一项只取决于前两项，

因此可以使用两个变量来保存前两项的值，并且滚动更新，

这样一来可以把空间复杂度降低到O(1)

### 代码

```golang
// Time: O(n), Space: O(1)
func fib(N int) int {
   if N <= 0 { // 先处理最基本情况
      return 0
   }
   if N == 1 {
      return 1
   }
   first, second := 0, 1 // 定义两个临时变量,初始化为0和1
   // 接下来在for循环中计算当前项
   for i := 2; i <= N; i++ {
      third := first + second // 计算当前项
      first = second          // 并滚动更新
      second = third
   }
   return second // 最后返回second即可
}

```