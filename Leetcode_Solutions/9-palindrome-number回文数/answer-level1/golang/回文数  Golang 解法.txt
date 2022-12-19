### 解题思路
1. 如果 x 是负数，那么一定不是回文数
2. 将数字翻转，判断时候与原数字相同，以此判断是否是回文数。
判断方法：
> 1. 结果变量为 reverse，初始值为 0
> 2. 原数字除以 10， 取余；更新结果变量：reverse*10 + 前面的余数；更新 x：x=x/10
> 3. 如果 x > 0，则继续；直到 x==0，此时 x 的最高位也参与运算，翻转完毕。
> 4. 判断反转后的数字和原数字是否相等，返回结果。
3. 此外，不用考虑溢出，因为如果溢出就一定不是回文数。

### 代码

```golang
func isPalindrome(x int) bool {
    // 如果 x 是负数，则不是回文数
	if x < 0 {
		return false
	}
	y := x
	reverse := 0
	for x != 0 {
		remainder := x % 10
		reverse = reverse*10 + remainder
		x = x / 10
	}
	return reverse == y
}
```