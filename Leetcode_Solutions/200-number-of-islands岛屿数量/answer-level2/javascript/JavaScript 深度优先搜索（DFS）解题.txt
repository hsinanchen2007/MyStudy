一如既往的提供稀缺的js版本，核心思想是深度优先搜索。算法就是遍历网格，把所有1周围相连的岛屿‘兄弟’和他自己都变成‘0’，这里主要用了递归方法搜索上下左右四个方向的‘兄弟’。当找不到相连的‘兄弟’时计数一次。这也正是深度优先搜索的抽象说法。
```
var numIslands = function(grid) {
	if (grid.length === 0 || grid[0].length === 0) {
		return 0
	}
	let count = 0
    for (let i = 0, len = grid.length; i < len; i ++) {
    	for(let j = 0, len = grid[0].length; j < len; j ++) {
    		if(grid[i][j] != 0) {
    			count ++
    			findIslandSlibings(i, j)	
    		}
    	}
    }
    function findIslandSlibings (i, j) {
    	grid[i][j] = 0 // 先拿掉当前的岛屿
    	if(grid[i][j + 1] == 1) {
    		findIslandSlibings(i, j + 1)
    	}
    	if(grid[i][j - 1] == 1) {
    		findIslandSlibings(i, j - 1)
    	}
    	if(grid[i - 1] &&　grid[i - 1][j] == 1) {
    		findIslandSlibings(i - 1, j)
    	}
    	if(grid[i + 1] &&　grid[i + 1][j] == 1) {
    		findIslandSlibings(i + 1, j)
    	}
    }
    return count
};
```
