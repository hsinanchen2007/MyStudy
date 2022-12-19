
go语言版本：深度优先搜索、广度优先搜索、并查集解法。

![image.png](https://pic.leetcode-cn.com/b024265ae859dbcee136f73abc94c751c8a0099b647a66401f24e830d7872801-image.png)


## 主要参考

- <https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/>
- <https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/>
- <https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-bfsdfsbing-cha-ji-by-coldme-2/>

这些题解都是比较好的，讲的也挺详细，但我在实现时发现他们或多或少存在一些错误。我下面给出的解法中，除了Sol_1_1（使用BFS）未通过（有路过的高手可以帮忙看下问题出在哪，我自己的话下次刷这题再来想想），其他解法都通过测试。深度优先搜索的递归实现版本在本题应该是最优解了。

## 实现与整理

```go
package lt200

import (
	"container/list"
	"github.com/azd1997/Leetcode-training/ltmath"
)

//给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
//
//示例 1:
//
//输入:
//11110
//11010
//11000
//00000
//
//输出: 1
//示例 2:
//
//输入:
//11000
//11000
//00100
//00011
//
//输出: 3

// 参考 https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
// 解法：有三种：DFS、BFS、并查集

// 1. BFS（辅助队列）
// 坐标的转换 (x, y) -> x*cols + y。 假设一行三列，如果是(0,2)变成(0,3)后越界，但(0,3) -> 3 -> (1,0)
// 因此，在使用坐标转换之前一定要确保其不出界
func Sol_1_1(grid [][]byte) int {

	// 方向数组，通过方向偏移量实现。默认查找顺序为：上、右、下、左
	//	(0,0)  ------------->  y			起始点为左上角，x轴为往下（行数增），y轴表示往右（列数增）
	//	  |
	//	  |			  (x-1,y)
	//	  |	 (x,y-1)  (x,y)	(x,y+1)
	//	  |			  (x+1,y)
	//	  v
	//	  x
	direction := [][]int{{-1, 0}, {0, 1}, {1, 0}, {0, -1}} // direction[k][0]为x向偏移量， direction[k][1]为y向偏移量

	rows := len(grid) // 查看grid行数
	if rows == 0 {
		return 0 // 行数为0,什么格子都没有，自然也没有岛屿
	}

	cols := len(grid[0])                         // 获取列数
	marked := ltmath.TwoDimBoolArray(rows, cols) // 构建grid等规模二维布尔值数组，用来对遍历过的“1”进行标记
	//array := make([]bool, cols)
	//var marked [][]bool
	//for i:=0; i<rows; i++ {
	//	marked = append(marked, array)
	//}

	count := 0 // 岛屿数量

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			// 从上往下、从左往右遍历所有格子

			if !marked[i][j] && grid[i][j] == '1' {
				count++
				queue := list.New()        // 用container/list模拟队列
				queue.PushBack(i*cols + j) // 存储当前格子的坐标位置。这里不使用数组存储坐标，而是将坐标转换为数字。
				marked[i][j] = true        // 当前格子坐标一入队就要标记已访问过

				// 队列非空时循环
				for queue.Len() != 0 {
					curNode := queue.Front()           // 取得队列头部节点
					queue.Remove(curNode)              // 移除队列头部节点
					curX := curNode.Value.(int) / cols // 从队列取出的当前处理的格子的x坐标
					curY := curNode.Value.(int) % cols // 从队列取出的当前处理的格子的y坐标
					// 得到向上、右、下、左 四个方向前进一步的四个格子的坐标，看有没有越界，格子是不是访问过，如果格子还是“1”的话就继续放入队列
					for k := 0; k < 4; k++ {
						newX, newY := curX+direction[k][0], curY+direction[k][1]
						if newX >= 0 && newX < rows && newY >= 0 && newY < cols && // 新格子在grid内
							grid[newX][newY] == '1' && !marked[newX][newY] { // 新格子是‘1’且未访问过
							queue.PushBack(newX*cols + newY) // 立马加入队列
							marked[newX][newY] = true        // 立马标记
						}
					}
				}
			}

		}
	}

	return count
}







// 2. BFS
// 使用切片模拟queue(比使用container/list模拟更好)
// 不适用标记数组（marked），访问过的话就将“1”修改为别的字符。大家都是修改回“0”，
// 如果岛屿数不多，我觉得可以修改为count值，这样最后打印出来很直观的看出有几个岛屿
// 如果岛屿数过多（超10），想要将count转为byte就比较麻烦了，得设计合适的映射
// 为图方便还是将访问过的置为'2'吧
// 47/47 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 23.53 % of golang submissions (3.3 MB)
func Sol_1_2(grid [][]byte) int {
	rows := len(grid)
	if rows == 0 {return 0}
	cols := len(grid[0])
	count := 0	// 岛屿数
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				count++
				BFS(grid, rows, cols, x, y)
			}
		}
	}
	return count
}


// BFS，rows,cols为grid行与列数， x,y为当前起始点行、列坐标
func BFS(grid [][]byte, rows, cols, x, y int) {
	queue := make([]int, 0)
	queue = append(queue, x, y)		// 将广度优先搜索的起始点坐标加入队尾
	grid[x][y] = '2'
	for len(queue) != 0 {	// 队列非空
		curX, curY := queue[0], queue[1]
		queue = queue[2:]		// 出队
		for k:=0; k<4; k++ {
			newX, newY := curX + dx[k], curY + dy[k]
			if newX>=0 && newX<rows && newY>=0 &&newY<cols && grid[newX][newY]=='1' {
				grid[newX][newY] = '2'
				queue = append(queue, newX, newY)	// 将符合该岛屿一部分的格子的坐标加入队列
			}
		}
	}
}

// 方向数组，通过方向偏移量实现。默认查找顺序为：上、右、下、左
//	(0,0)  ------------->  y			起始点为左上角，x轴为往下（行数增），y轴表示往右（列数增）
//	  |
//	  |			  (x-1,y)
//	  |	 (x,y-1)  (x,y)	(x,y+1)
//	  |			  (x+1,y)
//	  v
//	  x
var (							// 比二维数组更直观
	dx = [4]int{-1, 0, 1, 0}
	dy = [4]int{0, 1, 0, -1}	// 上右下左
)

// 3. BFS
// 广度优先遍历并不需要回溯，是否需要四个方向的搜索呢？可不可以换成只有向右和向下？
// 在题解区看到这个问题，我也不确定，来试验一下就知道了
func Sol_1_3(grid [][]byte) int {
	rows := len(grid)
	if rows == 0 {return 0}
	cols := len(grid[0])
	count := 0	// 岛屿数
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				count++
				BFS_RD(grid, rows, cols, x, y)
			}
		}
	}
	return count
}
// BFS，rows,cols为grid行与列数， x,y为当前起始点行、列坐标， RD表示 right/down
func BFS_RD(grid [][]byte, rows, cols, x, y int) {
	queue := make([]int, 0)
	queue = append(queue, x, y)		// 将广度优先搜索的起始点坐标加入队尾
	grid[x][y] = '2'
	for len(queue) != 0 {	// 队列非空
		curX, curY := queue[0], queue[1]
		queue = queue[2:]		// 出队
		for k:=0; k<2; k++ {
			newX, newY := curX + dx2[k], curY + dy2[k]
			if newX>=0 && newX<rows && newY>=0 &&newY<cols && grid[newX][newY]=='1' {
				grid[newX][newY] = '2'
				queue = append(queue, newX, newY)	// 将符合该岛屿一部分的格子的坐标加入队列
			}
		}
	}
}

var (							// 比二维数组更直观
	dx2 = [4]int{0, 1}
	dy2 = [4]int{1, 0}	// 右下
)

// 测试结果是不通过！
// 例如：
// 1  1  1					 1  2  3
// 0  1  0		为便于描述 =>  4  5  6
// 1  1  1					 7  8  9
// 岛屿数应该为1，但是按右下两个方向的搜索。1 -> 2 -> 3 -> 5 -> 8 -> 9，  7是在这一轮找不到的。


// 4. DFS递归实现
// 47/47 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 82.35 % of golang submissions (2.9 MB)
func Sol_1_4(grid [][]byte) int {
	rows := len(grid)
	if rows == 0 {return 0}
	cols := len(grid[0])
	count := 0	// 岛屿数
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				count++
				DFS(grid, rows, cols, x, y)
			}
		}
	}
	return count
}


// DFS，rows,cols为grid行与列数， x,y为当前起始点行、列坐标.
// 最简洁的写法是，直接递归。
func DFS(grid [][]byte, rows, cols, x, y int) {
	if x<0 || y<0 || x>=rows || y>=cols || grid[x][y]!='1' {return}
	grid[x][y] = '2'	// 搜索过的格子标记为‘2’
	for k:=0; k<4; k++ {DFS(grid, rows, cols, x+dx[k], y+dy[k])}
}

// 5. DFS栈实现 参照题解区ColdMe实现。他的观点是在每个网格在出栈之后立即标记，
// 但事实上，我以题给示例手动走一遍发现这样的做法，后果是标记不及时，会造成重复搜索，所以提交的结果也显示性能很差
// 47/47 cases passed (128 ms)
//Your runtime beats 5.05 % of golang submissions
//Your memory usage beats 5.88 % of golang submissions (6.2 MB)
func Sol_1_5(grid [][]byte) int {
	rows := len(grid)
	if rows == 0 {return 0}
	cols := len(grid[0])
	count := 0	// 岛屿数
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				count++
				DFS_Stack(grid, rows, cols, x, y)
			}
		}
	}
	return count
}


// DFS 基于栈的循环实现，rows,cols为grid行与列数， x,y为当前起始点行、列坐标.
//
func DFS_Stack(grid [][]byte, rows, cols, x, y int) {
	stack := make([]int, 0)
	stack = append(stack, x, y)		// 将深度优先搜索的起始点坐标压入栈顶（切片的尾端作栈顶）
	for len(stack) != 0 {	// 队列非空
		l := len(stack)
		curX, curY := stack[l-2], stack[l-1]
		stack = stack[:l-2]		// 出栈
		grid[x][y] = '2'		// 出栈之后立刻标记
		for k:=0; k<4; k++ {
			newX, newY := curX + dx[k], curY + dy[k]
			if newX>=0 && newX<rows && newY>=0 && newY<cols && grid[newX][newY]=='1' {
				stack = append(stack, newX, newY)	// 将符合该岛屿一部分的格子的坐标加入栈顶
			}
		}
	}
}

// 6. DFS栈实现 每个网格在入栈时立即标记，
//47/47 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 91.76 % of golang submissions (2.8 MB)
func Sol_1_6(grid [][]byte) int {
	rows := len(grid)
	if rows == 0 {return 0}
	cols := len(grid[0])
	count := 0	// 岛屿数
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				count++
				DFS_Stack2(grid, rows, cols, x, y)
			}
		}
	}
	return count
}


// DFS 基于栈的循环实现，rows,cols为grid行与列数， x,y为当前起始点行、列坐标.
func DFS_Stack2(grid [][]byte, rows, cols, x, y int) {
	stack := make([]int, 0)
	stack = append(stack, x, y)		// 将深度优先搜索的起始点坐标压入栈顶（切片的尾端作栈顶）
	grid[x][y] = '2'		// 入栈之后立刻标记
	for len(stack) != 0 {	// 队列非空
		l := len(stack)
		curX, curY := stack[l-2], stack[l-1]
		stack = stack[:l-2]		// 出栈
		for k:=0; k<4; k++ {
			newX, newY := curX + dx[k], curY + dy[k]
			if newX>=0 && newX<rows && newY>=0 && newY<cols && grid[newX][newY]=='1' {
				stack = append(stack, newX, newY)	// 将符合该岛屿一部分的格子的坐标加入栈顶
				grid[newX][newY] = '2'		// 出栈之后立刻标记
			}
		}
	}
}

// 6. 使用并查集
// 并查集（disjoint-set 或叫 union-find-set），常用来求无向图的连通分量
// 使用并查集求无向图连通分量，在无向图有新节点动态加入时，比每加入新边就重新DFS要快的多。
// 本题的情况是无向图静态，因此，该方法并不占优。
// 该方法时间复杂度O(mn)，空间也是O(mn)
//47/47 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 15.29 % of golang submissions (3.7 MB)
func Sol_1_7(grid [][]byte) int {
	if grid == nil || len(grid) == 0 {return 0}
	rows, cols := len(grid), len(grid[0])
	ufs := UnionFind(grid)		// 遍历一遍生成并查集，初始状态
	for x:=0; x<rows; x++ {
		for y:=0; y<cols; y++ {
			if grid[x][y] == '1' {
				grid[x][y] = '2'	// 将访问过的陆地格子标记
				// 向四周搜索，看能否与自己合并（在本题中其实只需要向右下两个方向搜索）
				for k:=0; k<2; k++ {
					newX, newY := x + dx2[k], y + dy2[k]
					if newX>=0 && newX<rows && newY>=0 && newY<cols && grid[newX][newY]=='1' {
						ufs.Union(x*cols+y, newX*cols+newY)		// 合并两个相邻的岛屿
					}
				}

			}
		}
	}
	return ufs.count
}

// 并查集
type UnionFindSet struct {
	parent []int	// 来源节点
	rank   []int	// 秩
	count	int		// 孤立不相连区域 的数量。 对应到题目里就是岛屿数
}

// 时间O(mn)
func UnionFind(grid [][]byte) *UnionFindSet {
	rows, cols := len(grid), len(grid[0])
	ufs := &UnionFindSet{
		parent: make([]int, rows * cols),
		rank: make([]int, rows * cols),
	}
	// 遍历，填充生成并查集
	for i:=0; i<rows; i++ {
		for j:=0; j<cols; j++ {
			if grid[i][j] == '1' {
				ufs.parent[i*cols + j] = i*cols + j		// i*cols+j为坐标转换；parent[x]=x表示自己是自己的parent。初始状态下先这样填
				ufs.count++								// 统计grid中有多少个'1'
			}
			ufs.rank[i*cols+j] = 0						// 如果'0'，格子的秩为0
		}
	}
	return ufs
}

// 路径压缩（找到父亲的父亲的...， 也就是找到最古老的祖宗，然后，将中间路径压缩，使 parent[i] = i的祖宗 ）
func (ufs *UnionFindSet) Find(i int) int {
	if ufs.parent[i] != i {					// 如果i的祖宗不是自己，就去不断的找父亲（最终找到祖宗）
		ufs.parent[i] = ufs.Find(ufs.parent[i])
	}
	return ufs.parent[i]
}

// 从Find函数可以看出，如果所有节点本来就没有父亲，那么最终并查集的'1'格子都是孤立的
// 但是在Union操作中会通过合并，使得一些格子的秩会增加。

// 按秩合并
func (ufs *UnionFindSet) Union(x, y int) {
	rootX, rootY := ufs.Find(x), ufs.Find(y)	// 找到x,y各自的祖宗
	if rootX != rootY {		// 祖宗不是同一个就合并
		switch {
		case ufs.rank[rootX] > ufs.rank[rootY]:
			ufs.parent[rootY] = rootX		// y合并到x
		case ufs.rank[rootX] < ufs.rank[rootY]:
			ufs.parent[rootX] = rootY		// x合并到y
		default:	// 相等的情况下合并到哪个都一样。但是最好选择离待处理格子近的，这样的话Find操作可以少一些递归。不过这里我们也不知道，就随便一个
			ufs.parent[rootY] = rootX	// 将y祖宗为根节点的树 并到 x祖宗为根节点的树
			ufs.rank[rootX]++	// rootX的秩（rank）加1
		}
		ufs.count--		// 每合并两个格子成一块区域，grid中的孤立区域数就 减1
	}
}

// 返回无向图全部孤立区域数
func (ufs *UnionFindSet) Count() int {
	return ufs.count
}


```