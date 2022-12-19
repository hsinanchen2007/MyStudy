### 解题思路
填海bfs，把每个1都变成0，变成0的时间就是离0的距离

### 代码

```golang
func updateMatrix(matrix [][]int) [][]int {
	if len(matrix) == 0 {
		return nil
	}
	res, q, distance := make([][]int, len(matrix)), list.New(), 0
	for i := range res {
		res[i] = make([]int, len(matrix[0]))
	}
	for i := range matrix {
		for j := range matrix[0] {
			if matrix[i][j] == 0 {
				q.PushBack([2]int{i, j})
			}
		}
	}
	for q.Len() != 0 {
		temp := q
		q = list.New()
		for temp.Len() != 0 {
			now := temp.Remove(temp.Front()).([2]int)
			res[now[0]][now[1]] = distance
			if now[0]+1 < len(matrix) && matrix[now[0]+1][now[1]] != 0 {
				matrix[now[0]+1][now[1]] = 0
				q.PushBack([2]int{now[0] + 1, now[1]})
			}
			if now[0]-1 > -1 && matrix[now[0]-1][now[1]] != 0 {
				matrix[now[0]-1][now[1]] = 0
				q.PushBack([2]int{now[0] - 1, now[1]})
			}
			if now[1]+1 < len(matrix[0]) && matrix[now[0]][now[1]+1] != 0 {
				matrix[now[0]][now[1]+1] = 0
				q.PushBack([2]int{now[0], now[1] + 1})
			}
			if now[1]-1 > -1 && matrix[now[0]][now[1]-1] != 0 {
				matrix[now[0]][now[1]-1] = 0
				q.PushBack([2]int{now[0], now[1] - 1})
			}
		}
		distance++
	}
	return res
}

```