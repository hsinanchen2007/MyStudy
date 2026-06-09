### 解题思路
Top-K问题。
不用排序，用Quick Select方法解决。
时间复杂度O(N)
空间复杂度O(1)

### 代码

```golang
func getLeastNumbers(arr []int, k int) []int {
	if k >= len(arr) {
		return arr
	}

	var recur func(arr []int, k int)
	recur = func(arr []int, k int) {

		s, e := 0, len(arr)-1
		c := arr[s]
		for s < e {
			for s < e {
				if arr[s] > c {
					break
				}
				s++
			}

			for e > s {
				if arr[e] <= c {
					break
				}
				e--
			}
			if e > s {
				arr[s], arr[e] = arr[e], arr[s]
			}
		}
		if arr[e] < arr[0] {
			arr[0], arr[e] = arr[e], arr[0]
		}
		if e > k {
			recur(arr[0:e], k)
		} else if e < k {
			recur(arr[e:], k-e)
		} else {
			return
		}
	}
	recur(arr, k)
	return arr[0:k]
}

```