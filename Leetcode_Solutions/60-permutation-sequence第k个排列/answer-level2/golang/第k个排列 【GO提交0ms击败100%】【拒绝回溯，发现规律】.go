## 结果

![image.png](https://pic.leetcode-cn.com/7ed1107fca4df2eaf86e88af4e3f9f58967f87a3c49fcf00235092cf047c3f92-image.png)

## 思路

拒绝回溯，发现规律
- 假设字符串有n位
- 固定第一位数时，后面n-1位数可以组合出`(n-1)!`个排列
- 所以可以根据n与k从左往右求出结果的每一位数


## Code

```
func getPermutation(n int, k int) string {
	var chars = []rune{'1', '2', '3', '4', '5', '6', '7', '8', '9'}
	var prefix []rune
	for i := n - 1; i >= 0; i-- {
		// p代表i的阶乘
		p := 1
		for j := i; j > 0; j-- {
			p *= j
		}
		// 计算出当前位置的数
		idx := 0
		for k > p {
			k -= p
			idx++
		}
		prefix = append(prefix, chars[idx])
		chars = append(chars[:idx], chars[idx+1:]...)
	}
	return string(prefix)
}
```
