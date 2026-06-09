具体看注释
```js
var maxDistance = function(grid) {
	//获取二维数组宽高
	let m = grid.length;
	let n = grid[0].length;

	let array = [];
	//遍历二维数组找到岛屿
	for (let i = 0; i < m; i++) {
		for (let j = 0; j < n; j++) {
			if (grid[i][j] === 1) {
				array.push([i, j]);
			}
		}
	}
	//如果没有岛屿或者全是岛屿，返回-1
	if (array.length === 0 || array.length === m * n) return -1;

	//声明BFS行，列的前进方向 即当前岛屿的上下左右
	const col = [-1, 1, 0, 0];
	const row = [0, 0, -1, 1];

	let temp = [];
	while (array.length) {
		//从一个岛屿向着汪洋大海前进
		temp = array.pop();
		//当前坐标
		const x = temp[0];
		const y = temp[1];

		for (let i = 0; i < 4; i++) {
			//	向着当前坐标的上下左右前进
			const xx = x + col[i];
			const yy = y + row[i];
			//条件判断，下次前进不能脱离m,n的范围
			if (xx < 0 || xx >= m || yy < 0 || yy >= n || grid[xx][yy] !== 0) {
				continue;
			} else {
				//如果符合更新当前海洋坐标与岛屿的距离
				grid[xx][yy] = grid[x][y] + 1;
				//将这个坐标放在数组中，待未来再次向深海前进
				array.unshift([xx, yy]);
			}
		}
	}
	//取最后一次出发的左边，输出结果
	return grid[temp[0]][temp[1]] - 1;
};
```
