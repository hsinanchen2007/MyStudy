### 解题思路
运用 BFS

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
	let queue = ['(']; // 队列
	let result = new Set();// 结果

	while (queue.length != 0) {
		let brackets_str = queue.shift();
		let brackets = brackets_str.split('');
		let left = brackets.filter(bracket => bracket == '(').length;  // 含有的 "(" 数
		let right = brackets.filter(bracket => bracket == ')').length; // 含有的 ")" 数

		if (left == n && right == n)
			result.add(brackets_str); // 加入结果

		// BFS ，把接下来可能的结果加入队列
		if (left < n) queue.push(brackets_str+'(');
		if (right < n && left != right) queue.push(brackets_str+')');
	}

	return Array.from(result);
};
```