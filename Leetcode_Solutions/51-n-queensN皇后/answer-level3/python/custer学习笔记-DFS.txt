# 思考

DFS深度优先搜索-每一行就是深度level，递归终止条件到达第N次，退出。

在每一层就只能放一个皇后，枚举每一列看要放在什么位置。

如何判断该格子能否放置皇后，

第一种暴力第二种剪枝，有效判断剩下哪些格子不用搜索，使用数组记录(row[i],col[j])。

撇在坐标系中，y=-x，即x+y等于一个常数，判断pie[i+y]=1。

捺在坐标系中，y-x等于一个常数，判断na[i-j]=1。

总结：
- 横线上，只需要在确定一个位置后，直接进行下一行即可。 
- 竖线上，将确定位置后所在列进行记忆化，之后的位置与出现过的所有列进行比对。 
- “撇”，经过的所有格子有一个共同点，那就是横坐标加上纵坐标的结果是相同的。例如撇经过的每个格子都是3，这个结果只有撇上的格子符合。我们只需要将这个结果记忆化即可。 
- “捺”，横坐标减去纵坐标的值进行记忆化。

# Python实现及优化

```python []
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        if n < 1: return []
        self.result = []
        # set可以使用负数，因为row-col可能为负数
        self.cols = set(); self.pie = set(); self.na = set()
        self.DFS(n, 0, [])
        return self._generate_result(n)
    
    def DFS(self, n, row, cur_state):
        # 递归终止条件
        if row >= n:
            self.result.append(cur_state)
            return
        
        # 对于每一层就是遍历所有的列
        for col in range(n):
            if col in self.cols or row + col in self.pie or row - col in self.na:
                continue # go to die!，看该col是否被占用，cols或pie或na
            
            # update the flags，把皇后放在该位置
            self.cols.add(col) 		# 更新cols，表示不能再放置皇后
            self.pie.add(row + col) # 更新pie，表示不能再放置皇后
            self.na.add(row - col)  # 更新na，表示不能再放置皇后
            
            self.DFS(n, row+1, cur_state + [col]) # 递归到下一层
            
            self.cols.remove(col) # 恢复，
            self.pie.remove(row + col)
            self.na.remove(row - col)
    
    def _generate_result(self, n):
        board = []
        for res in self.result:
            for i in res:
                board.append("." * i + "Q" + "." * (n - i - 1))
        
        return [board[i: i+n] for i in range(0, len(board), n)]
```
```python []
class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        def DFS(queens, xy_dif, xy_sum):
            p = len(queens)
            if p == n:
                result.append(queens)
                return None
            for q in range(n):
                if q not in queens and p-q not in xy_dif and p+q not in xy_sum:
                    DFS(queens+[q], xy_dif+[p-q], xy_sum+[p+q])
        
        result = []
        DFS([], [], [])
        return [ ["."*i + "Q" + "."*(n-i-1) for i in sol] for sol in result ]
```

# Go实现
学习自[算法梦想家](https://mp.***/s/_MOa1eVEN1hUyAgqFlP_6A)

及 代码优化

学习自[https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0051.n-queens/n-queens.go](https://github.com/aQuaYi/LeetCode-in-Go/blob/master/Algorithms/0051.n-queens/n-queens.go)

```go []
package main

import "fmt"

func solveNQueens(n int) [][]string {
	if n == 0 {
		return [][]string{}
	}
	var res [][]int
	cols := make(map[int]bool, n) // 记录'|'方向上的占用情况
	pie := make(map[int]bool, n)  // 记录'\'方向的对角线的占用情况
	na := make(map[int]bool, n)   // 记录'/'方向的对角线的占用情况
	dfs([]int{}, n, cols, pie, na, &res)
	return generateResult(res, n)
}

func dfs(rows []int, n int, cols, pie, na map[int]bool, res *[][]int) {
	row := len(rows)
	// 递归终止条件，访问的row行已经大于等于n*n的方格中n的个数了。
	if row == n {
		// Go的切片是地址，往结果数组中添加的时候一定要复制一份新的
		// 否则会被后序操作修改
		tmp := make([]int, len(rows))
		copy(tmp, rows)
		*res = append(*res, tmp)
		return
	}
	// 对于每一层就是遍历所有的列
	for col := 0; col < n; col++ {
		id1 := row + col - 1 // row + col - 1
		id2 := row - col - 1 // row - col - 1
		// 查看该列是否被占用，记录在cols、d1和d2中
		if !cols[col] && !pie[id1] && !na[id2] {
			// 标记占用，更新cols、d1、d2，表示该位置被占用，不能放置皇后
			cols[col], pie[id1], na[id2] = true, true, true
			// 递归到下一层
			dfs(append(rows, col), n, cols, pie, na, res)
			// 解除标记不影响下次递归使用
			cols[col], pie[id1], na[id2] = false, false, false
		}
	}
}
func generateResult(res [][]int, n int) (result [][]string) {
	for _, v := range res {
		var s []string
		for _, val := range v {
			str := ""
			for i := 0; i < n; i++ {
				if i == val {
					str += "Q"
				} else {
					str += "."
				}
			}
			s = append(s, str)
		}
		result = append(result, s)
	}
	return
}
func main() {
	n := 8
	fmt.Println(solveNQueens(n))
}
```

```go []
package main

import "fmt"

func solveNQueens(n int) [][]string {
	if n == 0 {
		return [][]string{}
	}
	cols := make([]bool, n)
	d1 := make([]bool, 2*n) // 记录'\'方向的对角线的占用情况
	d2 := make([]bool, 2*n) // 记录'/'方向的对角线的占用情况
	board := make([]string, n)
	var res [][]string
	dfs(0, cols, d1, d2, board, &res)
	return res
}

func dfs(r int, cols, d1, d2 []bool, board []string, res *[][]string) {
	// 递归终止条件，访问的row行已经大于等于n*n的方格中n的个数了。
	if r == len(board) {
		// Go的切片是地址，往结果数组中添加的时候一定要复制一份新的
		// 否则会被后序操作修改
		tmp := make([]string, len(board))
		copy(tmp, board)
		*res = append(*res, tmp)
		return
	}
	// 对于每一层就是遍历所有的列
	n := len(board)
	for c := 0; c < len(board); c++ {
		id1 := r - c + n       // 标记捺的占用情况
		id2 := 2*n - r - c - 1 // 标记撇的占用情况
		// 查看该列是否被占用，记录在cols、d1和d2中
		if !cols[c] && !d1[id1] && !d2[id2] {
			b := make([]byte, n)
			for i := range b {
				b[i] = '.'
			}
			b[c] = 'Q'
			board[r] = string(b)
			// 标记占用，更新cols、d1、d2，表示该位置被占用，不能放置皇后
			cols[c], d1[id1], d2[id2] = true, true, true
			// 递归到下一层
			dfs(r+1, cols, d1, d2, board, res)
			// 解除标记不影响下次递归使用
			cols[c], d1[id1], d2[id2] = false, false, false
		}

	}
}

func main() {
	n := 14
	fmt.Println(solveNQueens(n))
}
```