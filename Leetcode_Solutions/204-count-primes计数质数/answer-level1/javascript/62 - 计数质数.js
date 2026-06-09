// # 62 - 计数质数

// ## 题目

// 统计所有小于非负整数 *n* 的质数的数量。

// **示例:**

// > 输入: 10
// > 输出: 4
// > 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。


// ## 解答

// 最直观的解法，就是把所有质数算出来，数一下。

// ### 厄拉多塞筛法

// > 作者：magicalchao
// > 链接：https://leetcode-cn.com/problems/count-primes/solution/ji-shu-zhi-shu-bao-li-fa-ji-you-hua-shai-fa-ji-you/

// 每计算一个数，都要把它的倍数去掉。到了n，数一下留下了几个数。

// ```js
var countPrimes = function (n) {
  let count = 0
  signs = []
  for (let i = 2; i < n; i++) {
    if (!signs[i]) {
      count++
      for (let j = 2 * i; j < n; j += i) {
        signs[j] = true
      }
    }
  }
  return count
};
// ```

// > Runtime: 136 ms, faster than 66.06% of JavaScript online submissions for Count Primes.
// >
// > Memory Usage: 135.7 MB, less than 13.33% of JavaScript online submissions for Count Primes.

// - signs是用来记录“已经找过的数的倍数”的。

// 在里面的j循环中，一个个把找过数的倍数，对应的sign，设置为true。这样外循环就不会进入if循环，也就不会计数了。

// - 外面的i循环是用来计数的，只要signs的数是false，就是质数，count就++

// 由于js里面判断`!signs[i]`，啥都没有也是false，因此就不用像题解那样规定好数组一共有几个位置了。

// ### js的优化

// 经过[@Aaron](https://leetcode-cn.com/u/aaron-54/)大佬的提点，signs的时候规定好数组的大小，能减少内存的使用

// 我猜js和go一样，超过了规定的容量，就会把多增加的容量翻倍，倒不如事先规定好要用多少

// ```js
var countPrimes = function (n) {
	...
  signs = new Array(n + 1)
  ...
};
// ```

// > Runtime: 92 ms, faster than 93.73% of JavaScript online submissions for Count Primes.
// >
// > Memory Usage: 57.9 MB, less than 86.67% of JavaScript online submissions for Count Primes.

// 天翻地覆的改变👌

// ### go

// ```go
func countPrimes(n int) int {
	count := 0
	signs := make([]bool, n)
	for i := 2; i < n; i++ {
		if signs[i] {
			continue
		}
		count++
		for j := 2 * i; j < n; j += i {
			signs[j] = true
		}
	}
	return count
}
// ```

// > Runtime: 8 ms, faster than 88.62% of Go online submissions for Count Primes.
// >
// > Memory Usage: 5 MB, less than 100.00% of Go online submissions forCount Primes.

// go就不能这么偷懒了，必须说明新建的这个切片是什么类型，有多少个位置。

// go的bool，默认为false。因此如果是true就能直接拿来判断。

