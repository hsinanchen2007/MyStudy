
![image.png](https://pic.leetcode-cn.com/182173a370eb74ffa6b6664a840b57f83467dc6fb924d6abb905e2ae5ad7a2f1-image.png)
1. 深度优先搜索 dfs
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var deepestLeavesSum = function(root) {
    let stack = [root], sum = 0, level = 0, maxLevel = 0
    let fn = (root, level) => {
        if (root === null) return
        if (level > maxLevel) {
            maxLevel = level
            sum = 0
        }
        if (root.left === null && root.right === null && level === maxLevel) sum += root.val
        if(root.left) {
            fn(root.left, level + 1)
        }
        if(root.right) {
            fn(root.right, level + 1)
        }
    }
    fn(root, 0)
    return sum
};
```

![image.png](https://pic.leetcode-cn.com/3278078a9598a1570b25758c5a4e91138db26c59228868a2c165f9d264a733c8-image.png)

2. 广度优先搜索 bfs
```
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var deepestLeavesSum = function(root) {
    let stack = [root], sum = 0
    while(stack.length) {
        let temp = []
        while(stack.length) {
            let root = stack.pop()
            if (root === null) return
            if (root.left === null && root.right === null) {
                sum += root.val
            }
            if (root.left) {
                temp.push(root.left)
            }
            if (root.right) {
                temp.push(root.right)
            }
        }
        stack = temp
        if (temp.length !== 0) sum = 0
    }
    return sum
};
```

