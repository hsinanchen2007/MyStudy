### 题目

面试题43. 1～n整数中1出现的次数
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

### 解题思路
![3113.jpg](https://pic.leetcode-cn.com/44629302f385512bb1a892af43cfd396e2af45779f11ff2b010ec9e54d6cad34-3113.jpg)




### 代码

```golang
func countDigitOne(n int) int {

	if n == 0 {
		return 0
	}
	k := 10
	left := 0
	right := 0
	midlle := 0
	ans := 0
	for {
		left = n / k
		right = n % (k/10)
		midlle = (n % k) / (k/10)

		ans += left * (k/10)
		
		if midlle > 1 {
			ans += 1 * (k/10)
		} else if midlle == 1 {
			ans += 1 * (right + 1)
		}
		if left == 0 {
			return ans
		}
		k = k * 10

	}
}
```