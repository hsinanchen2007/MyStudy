```
import (
	"sort"
)

type Elem struct {
	Count int
	Col   int
}

func kWeakestRows(mat [][]int, k int) (rst []int) {
	var (
		i, j   int
		length = len(mat)
		count  = make([]Elem, length)
	)

	if length == 0 {
		return nil
	}

    // 统计 1 个个数
	cols := len(mat[0])
	for i = 0; i < length; i++ {
		currCount := 0
		for j = 0; j < cols; j++ {
			if mat[i][j] == 0 {
				count[i] = Elem{
					Count: currCount,
					Col:   i,
				}
				break
			}
			currCount++
		}

		if j == cols {
			count[i] = Elem{
				Count: currCount,
				Col:   i,
			}
		}
	}

        // 根据 1 个个数，升序排序
	sort.SliceStable(count, func(i, j int) bool {
		return count[i].Count < count[j].Count
	})

        // 取前面 k 个即可
	for i = 0; i < k; i++ {
		rst = append(rst, count[i].Col)
	}
	return
}

```
