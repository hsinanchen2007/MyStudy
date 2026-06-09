列举所有情况，通过判断 A[i]和A[i-1]的大小，得到当前山的状态
山有三种状态， 上坡 asc，平坡，下坡 desc

1. 上坡状态下 ： A[i] > A[i-1], 继续上坡， now++
2. 上坡状态下 ： A[i] = A[i-1], 变平坡，不符合山脉特征， now = 0， asc = false
3. 上坡状态下 ： A[i] < A[i-1], 变下坡， 符合山脉特征， now++， asc = false， desc = true
4. 平坡状态下 ： A[i] > A[i-1], 变上坡， now = 2， asc = true， A[i-1]为山底，所以需要变成2。其余情况不需要考虑
5. 下坡状态下 ： A[i] < A[i-1], 继续下坡， now++
6. 下坡状态下 ： A[i] = A[i-1], 变平坡，不符合山脉特征， now = 0， desc = false
7. 下坡状态下 ： A[i] > A[i-1], 变上坡， 不符合山脉特征， now = 2， asc = true， desc = false

特别的，当状态为下坡时，已经符合山脉的特征，我们就可以去判断最大值了。
```
func longestMountain(A []int) int {
	max, now := 0, 0
	asc, desc := false, false
	for i := 1; i < len(A); i++ {
		if asc {
			if A[i] > A[i-1] {
				now++
			} else if A[i] < A[i-1] {
				asc = false
				desc = true
				now++
			} else {
				now = 1
				asc = false
			}
		} else if desc {
			if A[i] < A[i-1] {
				now++
			} else {
				asc = true
				desc = false
				now = 1
				if A[i] > A[i-1] {
					now = 2
				}
			}
		} else if A[i] > A[i-1] {
			asc = true
			now = 2
		}

		if desc {
			if now > max {
				max = now
			}
		}
	}
	return max
}
```
