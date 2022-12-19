### 解题思路

想要判断一个数的因子是否为2,3,5。只需要判断对这个几个数进行取模然后再除以这几个数，直到最后为1即是丑数。如果循环一趟下来num值没变，则一定不是丑数，所以，连续判断即可判断


### 代码

```golang
func isUgly(num int) bool {
	for num != 1 {
		var temp = num
		if num % 2 == 0 {
			num /= 2
		}
		if num % 3 == 0 {
			num /= 3
		}
		if num % 5 == 0 {
			num /= 5
		}
		if num == temp {
			return false
		}
	}
	return true
}
```