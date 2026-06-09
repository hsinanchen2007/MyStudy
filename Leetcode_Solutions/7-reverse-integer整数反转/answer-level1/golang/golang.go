golang解法
github: https://github.com/Crownt/leetcode

```
// 考虑在32位的机器上运行，必须预先检查向原整数附加另一位数字时是否会导致溢出
// int类型的范围是 -2^31——2^31-1，即-2147483648——2147483647,个位数分别是-8和7
// 当＇res>math.MaxInt32/10 || (res==math.MaxInt32/10 && temp>7)＇时，正向溢出
// 当＇res<math.MinInt32/10 || (res==math.MinInt32/10 && temp<(-8))＇时，负向溢出
// 时间复杂度：O(log10(x))，x中大约有log10(x)个数字　　空间复杂度：O(1) 

func reverse(x int) int {

	res := 0
	for x!=0 {
		temp := x%10

		// 由于＇res = res*10+temp＇可能会导致溢出，故需要提前检查　
		if res>math.MaxInt32/10 || (res==math.MaxInt32/10 && temp>7) {
			return 0
		}
		if res<math.MinInt32/10 || (res==math.MinInt32/10 && temp<(-8)) {
			return 0
		}

		res = res*10+temp
		x /= 10
	}

	return res
}
```
