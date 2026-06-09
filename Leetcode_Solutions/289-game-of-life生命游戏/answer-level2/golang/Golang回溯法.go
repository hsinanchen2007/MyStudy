# 递归调用check函数
**注：用visited矩阵记录当前节点是否已被访问**
1. 从[0,0]开始遍历矩阵中的每一个点
2. 首先判断当前点附近节点中存活和死亡节点个数，分别用live和die记录
3. 更改visited矩阵中当前节点的访问状态
4. 接着判断当前节点附近节点是否已被访问。如果有未被访问的节点，则调用check函数进入递归；如果周围节点都被访问过，则根据live和die判断并改变当前节点的状态
```
func gameOfLife(board [][]int)  {
    r := len(board)
	l := len(board[0])
    if r == 0 || l == 0{
        return
    }
	vis := make([][]int, r)  //生成与board形状一样的切片
	for i := 0; i < r; i++{
		vis[i] = make([]int, l)
	}
	check(0, 0, &board, &vis)
}

func check(i, j int, board *[][]int, visited *[][]int){
	round := [8][2]int{{0, 1},{1, 1},{1, 0},{1, -1},{0, -1},{-1, -1},{-1, 0},{-1, 1}}  //周围八个点的相对位移
	live := 0
	die := 0
	for n := 0; n < 8; n++ {                         //循环记录周围点的状态
		n_i, n_j := i+round[n][0], j+round[n][1]
		if n_i >= 0 && n_i < len(*board) && n_j >=0 && n_j < len((*board)[n_i]){   //检测是否越界
			if (*board)[n_i][n_j] == 0{
				die += 1
			}else{
				live += 1
			}
		}
	}
	(*visited)[i][j] = 1                              //改变visited矩阵，将当前节点改为已访问
	for m := 0; m < 8; m++{                           //循环判断周围节点是否已被访问
		m_i, m_j := i+round[m][0], j+round[m][1]
		if m_i >= 0 && m_i < len(*board) && m_j >=0 && m_j < len((*board)[m_i]){
			if (*visited)[m_i][m_j] == 0 {
				check(m_i, m_j, board, visited)
			}
		}
	}
	if (*board)[i][j] == 0 {                           //周围节点都被访问过了，开始改变当前节点状态
		if live == 3{
			(*board)[i][j] = 1
		}else{
			(*board)[i][j] = 0
		}
	}else{
		if live < 2{
			(*board)[i][j] = 0
		}else if live >=2 && live <= 3{
			(*board)[i][j] = 1
		}else if live > 3{
			(*board)[i][j] = 0
		}
	}
}
```
