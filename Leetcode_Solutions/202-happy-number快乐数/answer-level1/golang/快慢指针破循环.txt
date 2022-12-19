### 解题思路
第一种解法就是利用哈希表，存储每一次平方和的值，然后判断是否存在且是否为1。
第二种解法就是利用快慢指针法，因为无论是不是快乐数，最终都会进入循环。

### 代码

```golang
func calc(n int) int {
	sum := 0
	for n != 0 {
		sum += (n % 10) * (n % 10)
		n /= 10
	}
	return sum
}

func isHappy(n int) bool {
	fast := n
	slow := n

	for {
		fast = calc(fast)
		slow = calc(slow)
		slow = calc(slow)
		if fast == slow {
			break
		}
	}

	return fast == 1
}
```