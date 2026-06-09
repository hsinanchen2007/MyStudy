### 解题思路

1. 位运算
- 根据题意，最多只有9个格子，可以用9位以上的整型保存状态。这里为方便使用了普通的int。
- 在对格子进行改变操作时，首先根据修改的位置索引计算得到需要修改的位，并将得到的位与操作前的状态标记做异或运算即可得到改变后的状态标记，比如下例：

```
[1, 1, 1]    [1, 0, 1]
[1, 0, 1] -> [0, 1, 0]
[0, 0, 0]    [0, 1, 0]
```

状态数组对应的标记为 `111,101,000` ，假设此时需要对1行1列的0进行修改（起始下标为0）。则共需要修改5位，计算得到修改位为 `010,111,010`（计算方法可以参考代码中 change 函数的两层循环） ，将其与原标记进行异或运算，得到修改后的结果为 `101,010,010`

2. 广度优先搜索
- 搜索时，采用BFS方法，得到解后立刻返回
- 搜索过的格子无需再次搜索。比如，搜索了第一行的0、1号格子，在搜索路径为0、2的时候，无需考虑1号格子，因为在搜索路径0、1时已经完成搜索，也就是说，`0 -> 1 -> 2` 与 `0 -> 2 -> 1` 是重复的，因此在BFS的节点中另外保存了当前节点的搜索进度（下一次搜索的起始索引）

### 代码

```golang
var height, width int

type BfsNode struct {
	step, row, col, flag int
	next                 *BfsNode
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}

func change(originFlag, row, col int) int {
	changeFlag := 0
	for i := 0; i < height; i++ {
		for j := 0; j < width; j++ {
			changeFlag <<= 1
			if abs(i-row)+abs(j-col) <= 1 {
				changeFlag |= 1
			}
		}
	}
	return originFlag ^ changeFlag
}

func bfsSearch(initFlag int) int {
	queueHead := &BfsNode{0, 0, 0, initFlag, nil}
	queueTail := queueHead
	for queueHead != nil{
		nowNode := queueHead
		continueFlag := true
		for row := nowNode.row; row < height; row++ {
			col := 0
			if continueFlag { // 仅用于减少循环次数，不影响结果
				continueFlag = false
				col = nowNode.col
			}
			for ; col < width; col++ {
				newFlag := change(nowNode.flag, row, col)
				if newFlag == 0 {
					return nowNode.step + 1
				}
				if col+1 == width && row+1 < height{
					queueTail.next = &BfsNode{nowNode.step+1, row+1, 0, newFlag, nil}
				}else if col+1 < width{
					queueTail.next = &BfsNode{nowNode.step+1, row, col+1, newFlag, nil}
				}else{
					break
				}
				queueTail = queueTail.next
			}
		}
		queueHead = queueHead.next
	}
	return -1
}

func minFlips(mat [][]int) int {
	initFlag := 0
	height = len(mat)
	width = len(mat[0])
	// 初始化标记变量
	for _, row := range mat {
		for _, ele := range row {
			initFlag <<= 1
			if ele == 1 {
				initFlag |= 1
			}
		}
	}
	if initFlag == 0 {
		return 0
	}
	return bfsSearch(initFlag)
}
```