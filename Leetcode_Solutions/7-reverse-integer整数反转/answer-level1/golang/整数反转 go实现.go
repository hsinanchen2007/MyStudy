解题思路
反转的主要思路就是把一个数字的每位元素拆出来，在逆序加乘出一个结果。 我们主要用除法算式中商的概念。
(被除数-余数)÷除数=商

完整代码
```
func reverse(x int) int {
	var (
		limit int64 = 1 << 31
		maxNumber = limit - 1  // int32最大值
		minNumber = 0 - limit  // int32最小值
		reverseValue int64     // 避免反转结果溢出 用int64存储
		maxLen int = 10
	)
	divisors := []int{
		1,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
	}
	index := 0

	for i := maxLen - 1 /* 数组从0开始 */; i >= 0; i-- {
		divisor := divisors[i]
		quotient := int(x / divisor)
		if quotient == 0 && reverseValue == 0 {
			continue
		}
		reverseValue, x = int64( quotient * divisors[index] ) + reverseValue, int(x % divisor)
		index++
	}
	if x < 0 {
		reverseValue = 0 - reverseValue
	}
	if reverseValue > minNumber && reverseValue < maxNumber {
		return int(reverseValue)
	}
	return 0
}
```


执行结果
![image.png](https://pic.leetcode-cn.com/bf0b8011a3093e8ece63f1240acb613f2557c8d2a8cb3efb7ed735335484432f-image.png)
