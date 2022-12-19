```
func numOfSubarrays(arr []int, k int, threshold int) int {
	var (
		i, sum, count int
		length        = len(arr)
	)
	if length < k {
		return 0
	}
	if k == 1 {
		for i = 0; i < length; i++ {
			if arr[i] >= threshold {
				count++
			}
		}
		return count
	}

	for i = 0; i < k; i++ {
		sum += arr[i]
	}

	for i < length {
		if threshold*k <= sum {
			count++
		}
		sum -= arr[i-k]
		sum += arr[i]
		i++
	}
	if threshold*k <= sum {
		count++
	}
	return count
}
```
