### 解题思路
1. 创建行列数组参数；
2. 创建对角，反对角参数；
3. 玩家一每次行动，对应的行列+1，如果行列相同（对角）+1，或者行列的和等于棋盘大小-1则（反对角）+1；
4. 玩家二每次行动规则与玩家一相反（-1）；
5. 每次玩家行动结束后判断行列或者对角，反对角的值；
6. 值等于3，玩家一胜利（返回1）；值等于-3，玩家二胜利（返回2）；否则继续（返回0）。

### 代码

```golang
type TicTacToe struct {
    rows, cols [] int
	diagonal, antiDiagonal, size int
}

func Constructor(n int) TicTacToe {
    return TicTacToe{
		rows: make([]int, n),
		cols: make([]int, n),
		diagonal: 0,
		antiDiagonal: 0,
        size: n,
	}
}

func (t *TicTacToe) Move(row int, col int, player int) int {
    if player == 1 {
		t.rows[row]++
		t.cols[col]++
		if row == col {
			t.diagonal++
		}
		if row + col == t.size - 1 {
			t.antiDiagonal++
		}
	}
	if player == 2 {
		t.rows[row]--
		t.cols[col]--
		if row == col {
			t.diagonal--
		}
		if row + col == t.size - 1 {
			t.antiDiagonal--
		}
	}
	if t.rows[row] == t.size || 
        t.cols[col] == t.size || 
        t.diagonal == t.size || 
        t.antiDiagonal == t.size {
		return 1
	}
	if t.rows[row] == -t.size || 
        t.cols[col] == -t.size || 
        t.diagonal == -t.size || 
        t.antiDiagonal == -t.size {
		return 2
	}
	return 0
}
```