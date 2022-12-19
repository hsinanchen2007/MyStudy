golang解法　　１．过程模拟法；２．记录层数的多源BFS

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)

1.过程模拟法

```go
// 腐烂过程模拟法：构造方法 'rotting()' 模拟一次腐烂过程.
//              若腐烂过程后新鲜橘子数小于腐烂过程前新鲜橘子数，则分钟数'times'加一并继续腐烂过程.
//              直至某次腐烂过程前后，新鲜橘子数不变.
//              此时,若新鲜橘子数为0，则全部橘子被腐烂，返回分钟数'time',否则返回＇-1＇    
// 时间复杂度：O(kmn)  空间复杂度：O(nm)  其中，k为腐烂过程所需的分钟数

var M int  // 行数
var N int  // 列数
var dir = [][]int{{-1,0}, {1,0}, {0,-1}, {0,1}}  // 方向
var flag [][]int  // 防止在一次腐烂过程中出现多次传递，即在本次腐烂过程中被腐烂的橘子不能去腐烂它四周的橘子
                  // flag[i][j]=1 表示本次腐烂过程中,（i,j)处的橘子是被腐烂的，不可腐烂其四周的橘子

func orangesRotting(grid [][]int) int {
	M = len(grid)
	N = len(grid[0])
	flag = make([][]int, M)
	for i:=0; i<M; i++ {
		flag[i] = make([]int, N)
	}

	times := 0  
	fresh_oranges_num := getNumOfFreshOranges(grid)
	rotting(grid)
	next_fresh_oranges_num := getNumOfFreshOranges(grid)

	for next_fresh_oranges_num<fresh_oranges_num {
		times++
		fresh_oranges_num = next_fresh_oranges_num
		rotting(grid)
		next_fresh_oranges_num = getNumOfFreshOranges(grid)
	}
	
	if getNumOfFreshOranges(grid)>0 {
		return -1
	}

	return times
}

func getNumOfFreshOranges(grid [][]int) int {
	cnt := 0
	for i:=0; i<M; i++ {
		for j:=0; j<N; j++ {
			if grid[i][j]==1 {
				cnt++
			}
		}
	}

	return cnt
}

// 模拟一次腐烂过程，注意在本次腐烂过程中被腐烂的橘子不可向其四周传递腐烂
func rotting(grid [][]int) {
	for i:=0; i<M; i++ {
		for j:=0; j<N; j++ {
			if grid[i][j]==2 && flag[i][j]==0 {  // flag[i][j]=0时，才可向四周腐烂
				for k:=0; k<4; k++ {
					next_i := i + dir[k][0]
					next_j := j + dir[k][1]

					if inArea(next_i, next_j) && grid[next_i][next_j]==1 {
						grid[next_i][next_j] = 2
						flag[next_i][next_j] = 1  // 标记在本次腐烂过程中，该橘子是被腐烂的状态
					}
				}
			}
		}
	}

	// 重置flag,防止影响下一次腐烂过程
	for i:=0; i<M; i++ {
		for j:=0; j<N; j++ {
			flag[i][j] = 0
		}
	}
}

func inArea(i int, j int) bool {
	return i>=0 && i<M && j>=0 && j<N;
}
```
２．记录层数的多源BFS法

```go
// 记录层数的多源BFS法，为了记录层数，需要记录维护每层入队节点的个数'cnt'
// 时间复杂度：O(mn)  空间复杂度：O(mn)  

var M_2, N_2 int
var dir_2 = [][]int{{-1,0}, {1,0}, {0,-1}, {0,1}}  // 方向

func orangesRotting(grid [][]int) int {
	M_2 = len(grid)
	N_2 = len(grid[0])

	var q [][2]int
	cnt := 0
	times := 0

	// 多源初始节点(初始所有腐烂的橘子)入队，并记录本层入队节点个数'cnt'
	for i:=0; i<M_2; i++ {
		for j:=0; j<N_2; j++ {
			if grid[i][j] == 2 {
				q = append(q, [2]int{i, j})
				cnt++
			}
		}
	}

	for len(q)>0 {
		temp := 0  // 中间变量，暂存下一层入队节点个数，本层节点全部出队后，更新给cnt

		// 对本层的cnt个节点出队，并扩展下一层节点，将满足条件的下层节点(新鲜橘子)入队
		// 注意，入队时要更新节点状态(新鲜橘子 -> 腐烂橘子)，避免重复入队
		for i:=0; i<cnt; i++ {
			x := q[0][0]
			y := q[0][1]
			q = q[1:]

			for k:=0; k<4; k++ {
				next_i := x + dir_2[k][0]
				next_j := y + dir_2[k][1]

				if inArea_2(next_i, next_j) && grid[next_i][next_j]==1 {
					grid[next_i][next_j] = 2  // 更新节点状态
					q = append(q, [2]int{next_i, next_j})
					temp++
				}
			}
		}
		cnt = temp  // 更新队列中节点个数
		if cnt>0 {  // 若新入队节点大于0,则表明有新橘子被腐烂，层数(也即时间）加一 
			times++
		}
	}

	for i:=0; i<M_2; i++ {
		for j:=0; j<N_2; j++ {
			if grid[i][j] == 1 {
				return -1
			}
		}
	}
	return times
}

func inArea_2(i int, j int) bool {
	return i>=0 && i<M_2 && j>=0 && j<N_2
}

```

