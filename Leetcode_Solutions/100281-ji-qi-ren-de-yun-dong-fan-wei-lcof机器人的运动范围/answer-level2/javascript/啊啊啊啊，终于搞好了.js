### 解题思路
大概就是BFS广度优先搜索，反正我讲的肯定不如官方讲的好就不讲了
我这个肯定是还得优化的

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
	// 计算数位和
	let isReachable = (nums, k) => {
		let sum = 0;
		nums.forEach(num => {
			num.toString().split('').forEach(val => {
				sum += parseInt(val);
			});
		});
		return (sum <= k);
	}

	let queue =  new Set(); //分析队列
	let visited = new Set();//已分析
	let result = 0; // 结果
	queue.add('0,0');

	while (queue.size != 0) {
		for (let point of queue) {
			if (visited.has(point)) break;
			else visited.add(point);
			queue.delete(point);
			point = point.split(',');
			point = [parseInt(point[0]), parseInt(point[1])];
			result ++;
			// 把所能及之处加入队列
			for ([x_apd, y_apd] of [[1,0], [0,1]]) {
				let w_point = [point[0]+x_apd, point[1]+y_apd];
				if (point[0]+x_apd < m
					&& point[1]+y_apd < n
					&& isReachable(w_point, k))
					queue.add(w_point.toString());
			}
		}
	}

	return result;
};

```