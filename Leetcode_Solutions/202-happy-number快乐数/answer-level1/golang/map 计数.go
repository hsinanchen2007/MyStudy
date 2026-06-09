### 解题思路
1. 创建一个 map 用来存储每个计算得出的和  
2. 如果某次得到和为 1,则该数为幸运数
3. 如果某次得到的数字非 1，并且该数未存在于 map 当中，将其添加进去
4. 如果得到的数字非 1，且该数存在于 map 当中，说明这个过程将会进入一个循环当中，返回 false

### 代码

```golang
func isHappy(n int) bool {
	var cases = make(map[int]int)
	var flag bool
	for{
		sum := 0
		for n!=0{
			sum += (n%10)*(n%10)
			n /=10
		}
		if sum == 1 {
			flag = true
			break
		}else if _, ok := cases[sum]; ok {
			flag = false
			break
		}else {
			cases[sum] = 1
			n = sum
		}
	}
	return flag

}
```