```
func isPerfectSquare(num int) bool {
    if num == 1 || num == 4 {
		return true
	} else if num < 8 {
		return false
	}
	start := 1
	var end = num / 2
	var tmp int
	var res = false
	for {
		if end-start < 2 {
			break
		}
		if start*start == num || end*end == num {
			res = true
			break
		}
		tmp = (start + end) / 2
		if tmp*tmp == num {
			res = true
			break
		} else if tmp*tmp > num {
			end = tmp
		} else if tmp*tmp < num {
			start = tmp
		}
	}
	return res
}
```
