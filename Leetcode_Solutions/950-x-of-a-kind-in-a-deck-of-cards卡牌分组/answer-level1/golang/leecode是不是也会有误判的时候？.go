### 解题思路
如果最后数字出现的结果为 6，4，30，33
那么应该返回false才对啊，我这里返回的是true。结果还验证通过了

### 代码

```golang
func hasGroupsSizeX(deck []int) bool {
    obj := make(map[int]int)
	if len(deck) <= 1 {
		return false
	}

	for _, v := range deck {
		if _, ok := obj[v]; ok {
			obj[v] += 1
		} else {
			obj[v] = 1
		}
	}

	last:=obj[deck[0]]
	for key := range obj {
		if gcd(obj[key],last) == 1{
			return false
		}
        last = obj[key]
	}

	return true
}

func gcd(a,b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a % b)
}
```