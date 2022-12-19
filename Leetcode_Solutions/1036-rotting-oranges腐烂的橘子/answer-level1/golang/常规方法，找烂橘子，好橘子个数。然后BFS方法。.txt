### 解题思路
常规方法，找烂橘子，好橘子个数。然后BFS方法。

### 代码

```golang
func orangesRotting(grid [][]int) int {
	
	time := 0
	var queue [][]int //存放坏掉的橘子
	goodOrg := 0

	//首先找到滥掉的橘子，把烂橘子放到列队里面去
	for y := 0; y < len(grid); y++ {
		for x := 0; x < len(grid[y]); x++ {
			if grid[y][x] == 2 {
				fmt.Printf("烂苹果的位置:y:%d x:%d \n\r", y, x)
				queue = append(queue, []int{y, x})
			} else if grid[y][x] == 1 {
				fmt.Printf("美丽苹果的位置:y:%d x:%d \n\r", y, x)
				goodOrg++
			}
		}
	}

	fmt.Printf("坏苹果总数： %d 个 好苹果总数: %d 个 \n\r ", len(queue), goodOrg)

	h := len(grid) - 1    //格子的高度
	w := len(grid[0]) - 1 //格子的宽度

	//循环找烂橘子，将烂橘子周围上下左右变成烂橘子
	for len(queue) > 0 && goodOrg > 0 {
		time++
		fmt.Printf("time:%d \r\n ========================= \r\n", time)
		tLen := len(queue)
		for i := 0; i < tLen; i++ {
			coordinate := queue[i]
			y := coordinate[0]
			x := coordinate[1]

			//上
			if y-1 >= 0 && grid[y-1][x] == 1 {
				fmt.Printf("坐标：y:%d x:%d 上 是好苹果 坐标 y:%d x:%d 当前苹果值：%d \n\r", y, x, y-1, x, grid[y-1][x])
				grid[y-1][x] = 2
				queue = append(queue, []int{y - 1, x})
				goodOrg--
			}

			//下
			if y+1 <= h && grid[y+1][x] == 1 {
				fmt.Printf("坐标：y:%d x:%d 下 是好苹果 坐标 y:%d x:%d  当前苹果值：%d \n\r", y, x, y+1, x, grid[y+1][x])
				grid[y+1][x] = 2
				queue = append(queue, []int{y + 1, x})
				goodOrg--
			}

			//左
			if x-1 >= 0 && grid[y][x-1] == 1 {
				fmt.Printf("坐标：y:%d x:%d 左边 是好苹果 坐标 y:%d x:%d  当前苹果值：%d \n\r", y, x, y, x-1, grid[y][x-1])
				grid[y][x-1] = 2
				queue = append(queue, []int{y, x - 1})
				goodOrg--
			}

			//右
			if x+1 <= w && grid[y][x+1] == 1 {
				fmt.Printf("坐标：y:%d x:%d 右 是好苹果 坐标 y:%d x:%d  当前苹果值：%d \n\r", y, x, y, x+1, grid[y][x+1])
				grid[y][x+1] = 2
				queue = append(queue, []int{y, x + 1})
				goodOrg--
			}
		}
		queue = queue[tLen:]
	}
	if goodOrg > 0 { //还有健康的
		return -1
	} else {
		return time
	}
}
```