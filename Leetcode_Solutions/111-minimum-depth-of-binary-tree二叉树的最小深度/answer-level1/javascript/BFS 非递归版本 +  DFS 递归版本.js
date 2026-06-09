```
// BFS 非递归版本
var minDepth = function(root) {
	if(!root) return 0;
	let res = 1;
	const queue = [root];
	let i = queue.length;
	while(i) {
		while(i--) {
			const front = queue.shift();
			if(!front) continue;
			if(!front.left && !front.right) return res;
			queue.push(front.left);
			queue.push(front.right);
		}
		i = queue.length;
		res++;
	}
};

// DFS 递归版本
var minDepth = function(root) {
	let res = 0;
	(function getDeep(root, deep) {
		if(!root) return;
		deep++;
		if(!root.left && !root.right)
			res = res ? Math.min(res, deep) : deep;
		getDeep(root.left, deep);
		getDeep(root.right, deep);
	})(root, 0);
	return res;
};
```

