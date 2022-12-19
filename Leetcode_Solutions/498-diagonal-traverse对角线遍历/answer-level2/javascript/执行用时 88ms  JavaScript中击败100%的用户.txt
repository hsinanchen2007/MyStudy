### 解题思路
借鉴了下大佬的思路

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findDiagonalOrder = function(matrix) {
    // 设m为纵坐标，n为横坐标
    // 据题意可知，当m+n为奇数时向下遍历，m+n为偶数时向上遍历
    
    // 遍历方式
    // 向上遍历时：m递减，n递增
    // 向下遍历时：m递增，n递减
    // 以此循环
    
    /** 遍历结束条件
     *  向上遍历：m递减到0或者n递增到最大值
     *  向下遍历：n递减到0或者m递增到最大值
     */
    
    // 初始化返回值
    let res = [];
    let m = matrix.length;
    // 判断输入值长度为0直接返回
    if (m === 0 || (m > 0 && matrix[0].length === 0)) return res;
    let n = matrix[0].length;
    // 定义Boolean traversal值为此时的遍历方式为向上还是向下
    let traversal = true;
    // 循环
	for (let i = 0; i < m + n - 1; i++)
	{
		let pm = traversal ? m : n;
		let pn = traversal ? n : m;

        // 保证了x + y = i;
		let x = (i < pm) ? i : pm - 1;
		let y = i - x;                

		while (x >= 0 && y < pn)
		{
			res.push(traversal ? matrix[x][y] : matrix[y][x]);
			x--;
			y++;
		}

		traversal = !traversal;
	}
	return res;
};
```