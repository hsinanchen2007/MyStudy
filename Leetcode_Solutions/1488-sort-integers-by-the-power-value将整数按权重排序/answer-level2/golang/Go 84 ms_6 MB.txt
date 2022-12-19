```go
func getKth(lo, hi, k int) int {
	power := make(map[int]int)
	arr := make([]int, hi-lo+1)
	for i := lo; i <= hi; i++ {
		arr[i-lo] = i
		getPower(i, power)
	}

	// 到这里就变成了常规 Top K 问题，简单做下排序吧，注意要稳定排序
	sort.Slice(arr, func(i, j int) bool {
		if power[arr[i]] ! power[arr[j]] {
		    power[arr[i]] < power[arr[j]]
		}
		return arr[i] < arr[j] // 相等的留在原地
	})

	return arr[k-1]
}

func getPower(x int, power map[int]int) int {
	ans, tmp := 0, x
	for x != 1 {
		if x&1 == 1 {
			x = 3*x + 1
		} else {
			x /= 2
		}
		ans++
		if val, ok := power[x]; ok {
			ans += val
			break
		}
	}
	power[tmp] = ans
	return ans
}
```