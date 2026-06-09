### 解题思路
1. 首先分析周围存活细胞数
2. 然后判断死活
	- 周围活细胞等于3, 死细胞和活细胞都变活
	- 周围活细胞等于2, 死细胞和活细胞保持原样
	- 周围活细胞不等于2也不等于3, 直接死

### 代码

```javascript
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
	// 测试了好几次才发现是原地算法，hhh学习了，
	// 不过既然是这样，就还要先解构赋值复制一个临时数组作参考数组
	let copied = board.map(array => [...array]); //工作生活分别储存，互不干扰 :p

	//分析周围存活细胞数量
	let analyzer = (env, pos) => {
		let total_alive = 0; // 存活细胞的数量
		let anz = [0,0]; // 待分析的细胞
		[-1, 0, 1].forEach(x_apd => {
			anz[0] = pos[0] + x_apd;
			[-1, 0, 1].forEach(y_apd => {
				anz[1] = pos[1] + y_apd;
				if (env.hasOwnProperty(anz[0])
					&& env[anz[0]][anz[1]] == 1)
							total_alive ++;
			});
		});
		return (env[pos[0]][pos[1]] == 1) ? (total_alive - 1) : total_alive;// 排除自己
	}

	let analyze_result; //分析结果
	for (let x = 0; x < copied.length; x++) {
		for (let y = 0; y < copied[x].length; y++) {
			analyze_result = analyzer(copied, [x, y]);
			if (analyze_result == 3)
				board[x][y] = 1; //直接复活
			else if (analyze_result != 2)
				board[x][y] = 0; //直接爆炸
			// 剩下的就保持原样就可以了
		}
	}
};

```