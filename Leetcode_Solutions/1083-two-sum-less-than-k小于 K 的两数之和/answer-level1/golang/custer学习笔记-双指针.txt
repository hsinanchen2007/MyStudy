```go
func twoSumLessThanK(A []int, K int) int {
	res := make([]int, 0)
	start, end := 0, 0
	for i := range A {
		start = i
		end = len(A) - 1
		for {
			if end == start {
				break
			}
			if A[start]+A[end] < K {
				res = append(res, A[start]+A[end])
			}
			end--
		}
	}
	sort.Ints(res)
	if len(res) == 0 {
		return -1
	}
	return res[len(res)-1]
}
```
学习自[caigogo](https://leetcode-cn.com/u/caigogo)

```go
func twoSumLessThanK(A []int, K int) int {
	n := len(A)
	max := -1
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			if A[i]+A[j] < K {
				if A[i]+A[j] > max {
					max = A[i] + A[j]
				}
			}
		}
	}
	return max
}
```


