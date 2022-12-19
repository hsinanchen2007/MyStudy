### 解题思路
遍历时候维护层级，不同层级输出数据顺序不同

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
var zigzagLevelOrder = function(root) {
    const res = []
    if (root) {
        const queue = [root]
        let level = 0
        while (queue.length) {
            const len = queue.length
            const arr = []
            if (level % 2) {
                for (let i = 0; i < len; i++) {
                    const node = queue.shift()
                    node.left && queue.push(node.left)
                    node.right && queue.push(node.right)
                    arr.unshift(node.val)
                }
            } else {
                for (let i = 0; i < len; i++) {
                    const node = queue.shift()
                    node.left && queue.push(node.left)
                    node.right && queue.push(node.right)
                    arr.push(node.val)
                }
            }
            res.push(arr)
            level ++
        }
    }
    return res
};
```