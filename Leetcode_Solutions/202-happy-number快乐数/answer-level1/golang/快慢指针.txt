### 解题思路
参考了热评Java中的快慢指针并用go改写

### 代码

```golang
func isHappy(n int) bool {
	fast := n
	slow := n
	for {
		slow = sum(slow)
		fast = sum(fast)
		fast = sum(fast)
		if fast==slow{
			break
		}
	}
	if fast==1{
		return true;
	}
	return false
}
func sum(m int) int {
	result := 0
	for {
		result += (m % 10) * (m % 10)
		m /= 10
		if m == 0 {
			break
		}
	}
	return result
}
```