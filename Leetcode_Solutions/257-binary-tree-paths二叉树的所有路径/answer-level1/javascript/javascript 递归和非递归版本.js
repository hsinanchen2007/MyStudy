```
// 递归的版本
var binaryTreePaths = function(root) {
	const res = [];
	function findNext(root, route) {
		if(!root) return;
		if(!root.left && !root.right) res.push(route);
		findNext(root.left, root.left ? route + '->' + root.left.val : route);
		findNext(root.right, root.right ? route + '->' + root.right.val : route);
	}
	findNext(root, (root && root.val) + '');
	return res;
}

// 非递归的版本
var binaryTreePaths = function(root) {
	if(!root) return [];
	const stack = [root];
	let i = 1;
	const route = [root.val + ''];
	const res = [];
	while(i) {
		while(i--) {
			const front = stack.pop();
			if(!front) continue;
			stack.push(front.left);
			stack.push(front.right);
			const resFront = route.pop();
            if(!front.left && !front.right) {
            	res.push(resFront);
            	continue;
            }
			front.left && route.push(resFront + '->' + front.left.val);
			front.right && route.push(resFront + '->' + front.right.val);
		}
		i = stack.length;
	}
	return res;
};
```
