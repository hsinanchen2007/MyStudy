```
// DFS 递归版本
var hasPathSum = function(root, sum) {
	let isSuit = false;
	function getNext(root, tempSum) {
		if(!root || isSuit) return;
		tempSum += root.val;
		if (!root.left && !root.right && tempSum === sum) {
			isSuit = true;
			return;
		}
		getNext(root.left, tempSum);
		getNext(root.right, tempSum);
	};
	getNext(root, 0);
	return isSuit;
};

// DFS 非递归版本
var hasPathSum = function(root, sum) {
	if(!root) return false;
	const stack = [root];
	const temps = [0];
	let i = stack.length;
	while(i) {
		while(i--) {
			const front = stack.pop();
			let temp = temps.pop();
			if(!front) continue;
			temp += front.val;
			if(!front.left && !front.right && temp === sum) return true;
			stack.push(front.left, front.right);
			temps.push(temp, temp);
		}
		i = stack.length;
	}
	return false;
}
```
