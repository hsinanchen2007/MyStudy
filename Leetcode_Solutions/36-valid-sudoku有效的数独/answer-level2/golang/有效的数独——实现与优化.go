
## 实现与整理

```go
package lt36

// 有效的数独

// 9×9的数独填入了1~9的一些数字
// 每行数字不重复； 每列不重复，每小格不重复

// 1. 暴力解法 三次循环+哈希表记录出现情况
// 504/504 cases passed (4 ms)
//Your runtime beats 75.86 % of golang submissions
//Your memory usage beats 49.44 % of golang submissions (3.3 MB)
func Sol_1_1(board [][]byte) bool {

	m := make(map[byte]bool)

	// board 默认就是 9*9 矩阵

	// 第一次循环，检查每一行
	for i:=0; i<9; i++ {		// 行
		for j:=0; j<9; j++ {	// 列
			if board[i][j] != '.' {
				if m[board[i][j]] {
					return false
				}
				m[board[i][j]] = true
			}
		}
		m = make(map[byte]bool)		// 重置哈希表
	}

	// 第二次循环，检查每一列
	for i:=0; i<9; i++ {		// 列
		for j:=0; j<9; j++ {	// 行
			if board[j][i] != '.' {
				if m[board[j][i]] {
					return false
				}
				m[board[j][i]] = true
			}
		}
		m = make(map[byte]bool)		// 重置哈希表
	}

	// 第三次循环，检查每一小数独
	var x, y int
	for i:=0; i<9; i++ {		// 小数独编号
		for j:=0; j<3; j++ {	// 行
			for k:=0; k<3; k++ {	// 列
				x, y = (i/3)*3+j, (i%3)*3+k
				if board[x][y] != '.' {
					if m[board[x][y]] {
						return false
					}
					m[board[x][y]] = true
				}
			}
		}
		m = make(map[byte]bool)		// 重置哈希表
	}

	return true
}

// 2. 暴力解法 三次循环+数组记录出现情况
//504/504 cases passed (4 ms)
//Your runtime beats 75.86 % of golang submissions
//Your memory usage beats 80.9 % of golang submissions (2.9 MB)
func Sol_1_2(board [][]byte) bool {

	m := make([]bool, 9)	// 数组作哈希表，因为只有1~9这几个数，对应的ASCII为49～57. '.'为46

	// board 默认就是 9*9 矩阵

	// 第一次循环，检查每一行
	for i:=0; i<9; i++ {		// 行
		for j:=0; j<9; j++ {	// 列
			if board[i][j] != '.' {
				if m[board[i][j]-'1'] {
					return false
				}
				m[board[i][j]-'1'] = true
			}
		}
		m = make([]bool, 9)		// 重置哈希表
	}

	// 第二次循环，检查每一列
	for i:=0; i<9; i++ {		// 列
		for j:=0; j<9; j++ {	// 行
			if board[j][i] != '.' {
				if m[board[j][i]-'1'] {
					return false
				}
				m[board[j][i]-'1'] = true
			}
		}
		m = make([]bool, 9)		// 重置哈希表
	}

	// 第三次循环，检查每一小数独
	var x, y int
	for i:=0; i<9; i++ {		// 小数独编号
		for j:=0; j<3; j++ {	// 行
			for k:=0; k<3; k++ {	// 列
				x, y = (i/3)*3+j, (i%3)*3+k
				if board[x][y] != '.' {
					if m[board[x][y]-'1'] {
						return false
					}
					m[board[x][y]-'1'] = true
				}
			}
		}
		m = make([]bool, 9)		// 重置哈希表
	}

	return true
}

// 3. 暴力解法 三次循环+位运算记录出现情况
//504/504 cases passed (4 ms)
//Your runtime beats 75.86 % of golang submissions
//Your memory usage beats 98.88 % of golang submissions (2.7 MB)
func Sol_1_3(board [][]byte) bool {

	// 1~9这几个数，对应的ASCII为49～57. '.'为46

	// 必须是无符号整形才能作移位的位数，另外m的长度至少要为10才能表示1~9的出现情况
	var m uint16 = 1	// 00 0000 0001	// 表示没有出现。 若1出现， 则 1 << 1
	var num uint8	// 数独数字

	// board 默认就是 9*9 矩阵

	// 第一次循环，检查每一行
	for i:=0; i<9; i++ {		// 行
		for j:=0; j<9; j++ {	// 列
			if board[i][j] != '.' {
				num = board[i][j]-'0'	// num = 1~9
				if (m >> num) & 1 == 1 {		// 右移num位再与1，结果若为0则未出现，为1则出现过
					return false
				}
				m = m ^ (1 << num)
			}
		}
		m = 1		// 重置
	}

	// 第二次循环，检查每一列
	for i:=0; i<9; i++ {		// 列
		for j:=0; j<9; j++ {	// 行
			if board[j][i] != '.' {
				num = board[j][i]-'0'
				if (m >> num) & 1 == 1 {
					return false
				}
				m = m ^ (1 << num)
			}
		}
		m = 1		// 重置
	}

	// 第三次循环，检查每一小数独
	var x, y int
	for i:=0; i<9; i++ {		// 小数独编号
		for j:=0; j<3; j++ {	// 行
			for k:=0; k<3; k++ {	// 列
				x, y = (i/3)*3+j, (i%3)*3+k
				if board[x][y] != '.' {
					num = board[x][y]-'0'
					if (m >> num) & 1 == 1 {
						return false
					}
					m = m ^ (1 << num)
				}
			}
		}
		m = 1		// 重置
	}

	return true
}


// 可以看见，从Sol_1_1 ~Sol_1_3，时间消耗几乎没变化，但是空间消耗在不断优化，几乎超越100%。其实把Sol_1_3中 x,y给省略掉可能就超越100%了

// 接下来就是优化时间，想办法将三次循环变成一次循环，那么就需要空间让步一些。不过好在使用位运算空间使用已经是O(1)，三倍也仍是O(1)

// 4. 一次循环 + 位运算
// 一次循环其实仍然需要比较那么多次。不过时间消耗却明显提升了，奇奇怪怪
//504/504 cases passed (0 ms)
//Your runtime beats 100 % of golang submissions
//Your memory usage beats 98.88 % of golang submissions (2.7 MB)
func Sol_1_4(board [][]byte) bool {

	var m1, m2, m3 uint16 = 1, 1, 1
	var num1, num2, num3 uint8	// 数独数字。由于只用到1~9，不用担心 uint(int)转换出现溢出等问题
	var x, y int	// 小数独时所用

	// 第一次循环，检查每一行
	for i:=0; i<9; i++ {		// 行
		for j:=0; j<9; j++ {	// 列

			// 检查行
			if board[i][j] != '.' {
				num1 = board[i][j] - '0' // num = 1~9
				if (m1 >> num1) & 1 == 1 {		// 右移num位再与1，结果若为0则未出现，为1则出现过
					return false
				}
				m1 = m1 ^ (1 << num1)
			}

			// 检查列
			if board[j][i] != '.' {
				num2 = board[j][i] - '0' // num = 1~9
				if (m2 >> num2) & 1 == 1 {		// 右移num位再与1，结果若为0则未出现，为1则出现过
					return false
				}
				m2 = m2 ^ (1 << num2)
			}

			// 检查小数独
			x, y = (i/3)*3 + j/3, (i%3)*3 + j%3		// 注意对于小数独遍历时，外层循环控制的是9个小数独的遍历。
			if board[x][y] != '.' {
				num3 = board[x][y] - '0' // num = 1~9
				if (m3 >> num3) & 1 == 1 {		// 右移num位再与1，结果若为0则未出现，为1则出现过
					return false
				}
				m3 = m3 ^ (1 << num3)
			}
		}
		m1, m2, m3 = 1, 1, 1		// 重置
	}

	return true
}

// 从Sol_1_4来看如果时间还想要提升，那就是减少比较次数：在Sol_1_4中 每个格子!= '.' 这个步骤其实是重复做了三遍。
// 但即便使用哈希表记录是否比较过，其实也省不了反而可能更慢些，而且占内存。
//
// 至于说判断格子是否重复这个判断是没办法省略的
// 尽管有些解法似乎是把判断重复合并起来了，但其实并没有省略总体比较次数，最多最多是可能提前发现了一个格子不符合规则。
// 这种策略和Sol_1_4的做法真不好比较谁更快。但很明显如果采取这种做法，我没办法复用m1,m2,m3，必须使用3*9=27个数来记录字符出现状态

// 综上，Sol_1_4接近完美答案
```

## 参考题解

- <https://leetcode-cn.com/problems/valid-sudoku/solution/you-xiao-de-shu-du-by-leetcode/>
- <https://leetcode-cn.com/problems/valid-sudoku/solution/java-wei-yun-suan-xiang-jie-miao-dong-zuo-biao-bia/>
- <https://leetcode-cn.com/problems/valid-sudoku/solution/java-wei-yun-suan-xiang-jie-miao-dong-zuo-biao-bia/>