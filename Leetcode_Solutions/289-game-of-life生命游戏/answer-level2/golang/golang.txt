```
package main

import (
	"fmt"
)

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func gameOfLife(board [][]int) {
	way := [3]int{0, 1, -1}
	row := len(board)
	col := len(board[0])
	// select every node
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			aliveNum := 0
			// select each direction
			// 和迷宫走法一样
			for x := 0; x < 3; x++ {
				for y := 0; y < 3; y++ {
					if way[x] != 0 || way[y] != 0 {
						r := way[x] + i
						c := way[y] + j
						// check border
						if (r >= 0 && r < row) && (c >= 0 && c < col) {
							if abs(board[r][c]) == 1 {
								aliveNum++
								fmt.Println(aliveNum, i, j)
							}
						}
					}
				}
			}
			// check status
			// alive ->dead
			if (board[i][j] == 1) && (aliveNum < 2 || aliveNum > 3) {
				board[i][j] = -1
			}
			// dead ->alive
			if (board[i][j] == 0) && (aliveNum == 3) {
				board[i][j] = 2
			}
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if board[i][j] > 0 {
				board[i][j] = 1
			} else {
				board[i][j] = 0
			}
		}
	}
}

// 生命游戏，第一眼觉得是个图题，后来才知道主要是为了练符合状态
// 需要变化的是结点本身的状态，改变依据是周围结点的状态
// 硬做的话提前备份一个二维数组就好，尝试一下原地算法
// 原地算法不依赖额外的资源或者依赖少数的额外资源，仅依靠输出来覆盖输入的一种算法操作。
// 需要对改变后的数组状态做一些新的标记，来避免与0/1状态混淆
/*
alive->dead :-1
alive->alive :1
dead->alive :2
*/
func main() {
	var board = make([][]int, 0)
	temp := []int{0, 1, 0}
	board = append(board, temp)
	temp = []int{0, 0, 1}
	board = append(board, temp)
	temp = []int{1, 1, 1}
	board = append(board, temp)
	temp = []int{0, 0, 0}
	board = append(board, temp)
	fmt.Println(board)
	gameOfLife(board)
	fmt.Println(board)
}

```
