第一步：先写一个函数判断一个数是否是完全平方数
```
func isSquare(x int) bool {
	s := math.Sqrt(float64(x))
	i := float64(int(s))
	return s == i
}
```
第二步，不考虑重复位置的回溯算法，如果已经使用len(A)，说明成功了，+1。
每次回溯完记得重置标记为
```
func backtrack(A []int, used []bool, now int, count int, sum *int) {
	if count == len(A) {
		*sum += 1
		return
	}
	for i := 0; i < len(A); i++ {
		if used[i] {
			continue
		}
		if isSquare(now + A[i]) {
			used[i] = true
			backtrack(A, used, A[i], count + 1, sum)
			used[i] = false
		}
	}
}

```
第三步，考虑重复位置。首先排序，然后找到上一个使用的数字，如果相同，直接continue
```
sort.Ints(A) // 在入口函数排序

// 判断上一个和当前是否相等
var flag bool
		for j := i - 1; j >= 0; j-- {
			if !used[j] {
				if	A[j] == A[i] {
					flag = true
				}
				break
			}
		}
		if flag {
			continue
		}
```
完整代码
```
func numSquarefulPerms(A []int) int {
	used := make([]bool, len(A))
	sum := 0
	sort.Ints(A)
	for i := 0; i < len(A); i++ {
		if i > 0 && A[i] == A[i-1] {
			continue
		}
		used[i] = true
		backtrack(A, used, A[i], 1, &sum)
		used[i] = false
	}
	return sum
}

func backtrack(A []int, used []bool, now int, count int, sum *int) {
	if count == len(A) {
		*sum += 1
		return
	}
	for i := 0; i < len(A); i++ {
		if used[i] {
			continue
		}
		var flag bool
		for j := i - 1; j >= 0; j-- {
			if !used[j] {
				if	A[j] == A[i] {
					flag = true
				}
				break
			}
		}
		if flag {
			continue
		}
		if isSquare(now + A[i]) {
			used[i] = true
			backtrack(A, used, A[i], count + 1, sum)
			used[i] = false
		}
	}
}

func isSquare(x int) bool {
	s := math.Sqrt(float64(x))
	i := float64(int(s))
	return s == i
}
```