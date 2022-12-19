
对于工程师来说，最有意义的方法就是借助缓存优化递归（Sol_1_3）和借助动态规划思想的方法（Sol_1_4， Sol_1_5）。

Binets解法太数学了，斐波那契数列递推公式在阶数n较大时误差变大

## 实现

```go
package lt70

import "math"

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//
//注意：给定 n 是一个正整数。

// 思考：
// n=1: 1种
// n=2: 2种
// n=3: 3种
// n=4 ?
// 这种题目是数学归纳（递推）的题目，但是如果自己一个一个列举情况，太慢太累
// 这时候就非常重要的一个思想： !!!! 将问题分解为 最近重复子问题 !!!!
// 将问题表示为 f(n) . f(1)=1, f(2)=2,
// 那么当台阶数为3时，不去考虑第一步是迈1还是迈2， 而是从第3级台阶向后退1（到达第2阶）或退2（到达第1阶）
// 那么 f(3) = f(1) + f(2)
// 也就是说，f(n) = f(n-1) + f(n-2) 其实就是个求斐波那契额数列的递归
// 当然递归实现效率太低，可以在循环里去完成这个事情

// 倒爬楼梯 递归。
// 时间O(2^n)，空间O(n) Leetcode超时
// 这个递归实现重复计算了许多次同样的值。效率很低
func Sol_1_1(n int) int {
	if n>2 {
		return Sol_1_1(n-1) + Sol_1_1(n-2)
	}
	return n	// 恰好f(1)=1, f(2)=2
}

// 顺爬楼梯递归
// climb(i, n) = climb(i+1, n) + climb(i+2, n)
// 时间O(2^n)，空间O(n) Leetcode执行超时
func Sol_1_2(n int) int {
	return climb(0, n)
}

func climb(i, n int) int {
	if i > n {
		return 0
	}
	if i==n {
		return 1	// 当前这级也需要计算在内
	}
	return climb(i+1, n) + climb(i+2, n)
}

// 顺爬楼梯，递归，加缓存（减少计算冗余）
// 时间O（N）,空间O(N)
// (倒爬楼梯没办法缓存。至少我没想到)
//45/45 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 7.39 % of golang submissions (2 MB)
func Sol_1_3(n int) int {
	if n<=3 {return n}	// 正好前三阶的走法与阶数对应
	memory := make([]int, n+1)	// n+1是为了下标直接和函数入参对应
	return climb2(0, n, memory)
}

func climb2(i, n int, memory []int) int {
	if i > n {
		return 0
	}
	if i==n {
		return 1	// 当前这级也需要计算在内
	}
	// 查看是否已经缓存了 climb2(i, n, memory)
	if memory[i] > 0 {	// 0是初始化的值，只要缓存过，就会刷新为一个正数
		return memory[i]
	}
	// 没缓存过，就计算，并缓存起来
	memory[i] = climb2(i+1, n, memory) + climb2(i+2, n, memory)
	return memory[i]
}

// 倒爬楼梯， 一遍循环实现。这个解法可能是最优的
// 这也是斐波那契数列一般的解法，足够高效
// 时间Ｏ(N),　空间Ｏ(1)
//45/45 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 90.87 % of golang submissions (1.9 MB)
func Sol_1_4(n int) int {
	if n <= 2 {return n}	// f(1)=1,f(2)=2
	f1, f2, f3 := 1, 2, 3	// 保存这三个情况下的走法数
	for i:=3; i<=n; i++ {	// 这其实是在用循环模拟走楼梯！
		f3 = f1 + f2	// f3 对应着走到第i阶的可能数， 它等于 走到第i-1阶 +　第ｉ-2阶
		// 如果循环还没停止，也就是还没走到n，下一次循环　ｉ变成　ｉ+1 ,它的走法 = f（ｉ－１）＋　ｆ(i)
		f1 = f2													//ｆ3  = f1     +      f2
		f2 = f3
	}
	// 这里举个例子，n=4, 进入循环体
	// i=3, f3=1+2=3, f1=2, f2=3
	// i=4, f3=2+3=5, f1=3, f2=5

	return f3
}

// 动态规划解法。其实Ｓｏｌ_1_4也是动态规划的思想
// 这个解法使用了一个数组用来记录动态规划的结果
// 时间Ｏ(n),空间Ｏ(n)
//45/45 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 37.83 % of golang submissions (2 MB)
func Sol_1_5(n int) int {
	if n <= 2 {return n}	// f(1)=1,f(2)=2
	f := make([]int, n+1)	// 保存到i阶的走法数
	f[1], f[2] = 1, 2
	for i:=3; i<=n; i++ {	// 这其实是在用循环模拟走楼梯！
		f[i] = f[i-1] + f[i-2]
	}

	return f[n]
}

// 在后来的刷题提交中，我又将Sol_1_5小改了一下，变成下面这个样子

// 顺爬楼梯 动态规划 + 辅助数组(缓存)  O(n)/O(n)
func climbStairs(n int) int {
    if n <= 3 {return n}    // 恰好的值，看题给示例
    memory := make([]int, n+1)  // 缓存数组下标即对应楼梯的阶数，存的值为对应的走法数
    memory[2], memory[3] = 2, 3     // 因为3也很容易知道，所以我就不用1和2，改用2和3
    for i:=4; i<=n; i++ {
        memory[i] = memory[i-1] + memory[i-2]   // 计算并更新缓存值
    } 
    return memory[n]
}

// Binets解法
// 参看官方题解. 涉及到矩阵的乘与幂，因此需要先实现这两个操作. 矩阵用二维数组表示
// 时间Ｏ(logn),空间Ｏ(1)
// 45/45 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 90.87 % of golang submissions (1.9 MB)
func Sol_1_6(n int) int {
	q := [2][2]int{{1,1}, {1,0}}
	res := pow(q, n)
	return res[0][0]
}

// 2阶方阵的幂
func pow(a [2][2]int, n int) [2][2]int {
	res := [2][2]int{{1,0}, {0,1}}	// 1 0
									// 0 1
	for n>0 {
		if n&1 == 1 {
			res = multi(res, a)
		}
		n = n>>1
		a = multi(a, a)
	}
	return res
}

// 2阶方阵相乘
func multi(a [2][2]int, b [2][2]int) [2][2]int {
	c := [2][2]int{}
	for i:=0; i<2; i++ {
		for j:=0; j<2; j++ {
			c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j]
		}
	}
	return c
}

// 使用斐波那契数列递推公式直接写
// 这个公式，当ｎ比较大时会出现偏差。而且实现它得使用go的math库（浮点型数据）
// 因此这个解法不能通过Leetcode测试，至少golang版是的
func Sol_1_7(n int) int {
	sqrt5 := math.Sqrt(5)
	fibn := math.Pow((1+sqrt5)/2, float64(n+1)) - math.Pow((1-sqrt5)/2, float64(n+1))
	return int(fibn/sqrt5)
}
```

## 参考题解

- <https://leetcode-cn.com/problems/climbing-stairs/solution/pa-lou-ti-by-leetcode/>