![图像 6.png](https://pic.leetcode-cn.com/996edb0f721788f6a871b872c44c105085b596b10ab3900fcd932dec740fbb5e-%E5%9B%BE%E5%83%8F%206.png)


倒序遍历整个切片，并且对元素+1在取余，如果为不为0，说明不会发生进位操作，直接返回
整个数组遍历完还没有遇到计算后的切片元素为0，说明遇到了999 99999等情况
对整个遍历后的切片尾插一个元素0，并将第一个元素置为0为最终结果
```
func plusOne(digits []int) []int {
	for i := len(digits)-1; i >=0; i-- {
		digits[i]++
		digits[i] = digits[i] % 10
		if digits[i] != 0 {
			return digits
		}
	}
	digits = append(digits, 0)
	digits[0] = 1
	return digits
}
```
