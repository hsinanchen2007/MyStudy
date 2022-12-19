### 解题思路
bfs解法
先将坏🍊坐标塞到队列，再传染其他🍊，继续加入队列。
注意方格边界

### 代码

```golang
func orangesRotting(grid [][]int) int {
	//空方格，返回0
	if len(grid) == 0 {
		return 0
	}

	w, h := len(grid), len(grid[0]) 
	queue := [][]int{} //坏🍊队列
	healthyCount := 0 //健康🍊总数

	for i := 0; i < w; i++ {
		for j := 0; j < h; j++ {
			if grid[i][j] == 2 {
				queue = append(queue, []int{i, j}) //塞队列
			} else if grid[i][j] == 1 {
				healthyCount++ //健康🍊数累加
			}
		}
	}

	var t = 0 //循环次数或层数或分钟数
	for healthyCount > 0 && len(queue) > 0 { //无健康🍊或队列为空， 跳出循环
		t++ //循环次数加1
		ql := len(queue) //本次循环要消费的队列数，因为队列后面会继续塞，所以这里先算出长度
		for i := 0; i < ql; i++ { //将本地的队列消费完 
			one := queue[0] //每次都是取出第一个，相当于队列头
			x, y := one[0], one[1] //坏🍊坐标
			queue = queue[1:] //队列头删掉，相当于出队列了

			if y-1 >= 0 && grid[x][y-1] == 1 { //上边的健康🍊
				grid[x][y-1] = 2 //感染
				healthyCount-- //健康🍊数减1
				queue = append(queue, []int{x, y - 1}) //被感染的🍊坐标塞入队列
			}

			if y+1 < h && grid[x][y+1] == 1 { //下边的健康🍊
				grid[x][y+1] = 2
				healthyCount--
				queue = append(queue, []int{x, y + 1})
			}

			if x-1 >= 0 && grid[x-1][y] == 1 { //左边的
				grid[x-1][y] = 2
				healthyCount--
				queue = append(queue, []int{x - 1, y})
			}

			if x+1 < w && grid[x+1][y] == 1 { //右边的
				grid[x+1][y] = 2
				healthyCount--
				queue = append(queue, []int{x + 1, y})
			}
		}
	}

	if healthyCount > 0 { //还有健康🍊，说明感染不完，返回-1
		return -1
	} else {
		return t
	}
}

```