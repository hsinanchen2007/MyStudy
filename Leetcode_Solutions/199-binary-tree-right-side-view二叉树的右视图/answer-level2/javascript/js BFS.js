```
var rightSideView = function(root) {
	const queue = [root];
	let i = queue.length;
	const res = [];
	while(i) {
        let right;
		while(i--) {
			const front = queue.shift();
			if(!front) continue;
            right = front.val;
			queue.push(front.left, front.right)
		}
		right && res.push(right);
		i = queue.length;
	}
	return res;
};
```
