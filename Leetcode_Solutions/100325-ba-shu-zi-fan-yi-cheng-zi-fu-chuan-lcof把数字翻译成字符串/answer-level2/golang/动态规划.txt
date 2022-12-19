用数字的每一位进行计算
不用转换成字符串，利用除法
```
func translateNum(num int) int {
    dp := []int{1} // 默认1个
	pn := -1       // 前一个数字(0-9)
	cn := 0        // 当前数字
	i := 0
	for num > 0 {
		dp = append(dp, 0) // 初始化当前数据
		i++
		cn = num % 10
		num = num / 10
		dp[i] = dp[i-1] // 肯定和上次变化一样
		if cn != 0 && pn >= 0 && cn*10+pn <= 25 {  // 两位可以结合(10-25)
			dp[i] += dp[i-2]
		}
		pn = cn
	}
	return dp[i]
}
```

// 空间O(1)的解法
// 从上诉动态规划中，我们只要保留i-2这一位的数量即可
```
func translateNum(num int) int {
    pn := -1    // 前一个数字(0-9)
	cn := 0     // 当前数字
	ans := 1    // 默认1个
	last := ans // 前一位的数量(i-2)
	for num > 0 {
		cn = num % 10
		num = num / 10
		// 可以结合[10-25]
		if cn != 0 && pn >= 0 && cn*10+pn <= 25 {
			ans, last = ans+last, ans
		} else {
			last = ans
		}
		pn = cn
	}
	return ans
}
```

