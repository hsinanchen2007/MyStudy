```
// 深度优先搜索递归版本
var maxDepth = function(root) {
    if(!root) return 0;
    return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
};

// 深度优先搜索迭代版本
var maxDepth = function(root) {
    let max = 0;
    if(!root) return max;
    const queue = [[root, 1]];
    max = 1;
    while(queue.length) {
        let len = queue.length;
        while (len--) {
            const [front, num] = queue.pop();
            const ifUpdateNum = num + 1;
            if(front.left) queue.push([front.left, ifUpdateNum]);
            if(front.right) queue.push([front.right, ifUpdateNum]);
            if(front.left || front.right) max = Math.max(max, ifUpdateNum);
        }
    }
    return max;
};

// 广度优先搜索迭代版本
var maxDepth = function(root) {
    let max = 0;
    if(!root) return max;
    const queue = [root];
    while(queue.length) {
        let len = queue.length;
        while (len--) {
            const front = queue.shift();
            if(front.left) queue.push(front.left);
            if(front.right) queue.push(front.right);
        }
        max++;
    }
    return max;
};
```

