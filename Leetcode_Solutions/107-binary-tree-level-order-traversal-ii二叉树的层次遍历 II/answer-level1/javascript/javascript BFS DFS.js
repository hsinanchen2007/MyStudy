### 解法一
BFS

### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrderBottom = function(root) {
    const res = []
    if (root) {
        const queue = [root]
        while (queue.length) {
            const len = queue.length
            const temp = []
            for (let i = 0; i < len; i++) {
                const node = queue.shift()
                temp.push(node.val)
                node.left && queue.push(node.left)
                node.right && queue.push(node.right)
            }
            res.unshift(temp)
        }
    }
    return res
};
```

### 解法二
DFS

### 代码
```javascript
var levelOrderBottom = function(root) {
    let res = []
    let queue = []
    if (root) {
        let level = 0
        queue.push({ node: root, level })
        while (queue.length) {
            const item = queue.shift()
            const node = item.node
            const level = item.level
            if (level === res.length) {
                res.unshift([])
            }
            res[0].push(node.val)
            node.left && queue.push({ node: node.left, level: level + 1 })
            node.right && queue.push({ node: node.right, level: level + 1 })
        }
    }
    return res
};
```