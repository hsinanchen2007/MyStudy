### 解题思路
试了好几次深搜+二分，都超时，改成宽搜+二分了

### 代码

```golang
func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}
func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

var dx = []int{-1, 0, 1, 0}
var dy = []int{0, 1, 0, -1}


type xyzhou struct {
	x int
	y int
}

func helpmax(mid int, A, visit [][]int) bool {

	lst := list.New()
	lst.PushBack(xyzhou{0, 0})

	for lst.Len() != 0 {
		e := lst.Front().Value.(xyzhou)
		for i := 0; i < 4; i++ {
			ddx := e.x + dx[i]
			ddy := e.y + dy[i]
			if ddx >= 0 && ddx < len(A) && ddy >= 0 && ddy < len(A[0]) && visit[ddx][ddy] != 1 && A[ddx][ddy] >= mid {
				visit[ddx][ddy] = 1
				lst.PushBack(xyzhou{ddx, ddy})
				if ddx == len(A)-1 && ddy == len(A[0])-1 {
					return true
				}
			}
		}
		lst.Remove(lst.Front())
	}

	return false
}
func maximumMinimumPath(A [][]int) int {

	low := 1
	high := min(A[0][0], A[len(A)-1][len(A[0])-1])
	result := 0
	for low <= high {
		visit := make([][]int, len(A))
		for i := 0; i < len(visit); i++ {
			visit[i] = make([]int, len(A[0]))
		}
		visit[0][0] = 1
		mid := (low + high) / 2
		if helpmax(mid, A, visit) == true {
			result = mid
			low = mid + 1
		} else {
			high = mid - 1
		}
	}
	return result
}
```