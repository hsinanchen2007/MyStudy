### 解题思路
在纸上画画不难发现其规律。  
比如
```javascript
[
	['0,0','0,1','0,2'],
	['1,0','1,1','1,2'],
	['2,0','2,1','2,2'],
]
```
> 用其中 `0,2` 打比方，那么它在matrix中的位置就是 `matrix[0][2]`，假设`0`是它的x坐标，`1`是它的y坐标

它旋转过一圈后就会是这样
```javascript
[
  [ '2,0', '1,0', '0,0' ],
  [ '2,1', '1,1', '0,1' ],
  [ '2,2', '1,2', '0,2' ]
]
```
> 单从一行可以看出，每个元素的x坐标呈递减，且从matrix的最大一位索引开始递减
> 单从一列可以看出，每个元素的y坐标呈递增，从0开始

### 实现

原理知道了，就该实现了。  
这是个原地算法，我觉得我这个代码不算最好，因为它复制了矩阵，浪费了一些内存。 //虽然内存消耗击败100%，hhhhh  
具体怎么实现看代码吧！

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
	let rotated = matrix.map(mtrx => [...mtrx]); // 复制矩阵
	for (let x = 0; x < rotated.length; x ++)
		for (let y = 0; y < rotated[x].length; y ++)
			matrix[x][y] = rotated[rotated.length-1-y][x];
};

```
