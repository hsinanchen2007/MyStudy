### 解题思路
利用hashmap判断是否是死循环

### 代码

```golang

func isHappy(n int) bool {
	m := make(map[int]bool)

	for {
		sum := getNum(n)
		fmt.Println(sum)
		if sum == 1 {
			return true
		} else {
			if _, ok := m[sum]; ok {
				return false
			}
			m[sum] = true
			n = sum
		}

	}

}

func getNum(n int) int {
	var result int
	for {
		result += (n % 10) * (n % 10)
		if n/10 == 0 {
			break
		}
		n = n / 10
	}
	return result
}
```