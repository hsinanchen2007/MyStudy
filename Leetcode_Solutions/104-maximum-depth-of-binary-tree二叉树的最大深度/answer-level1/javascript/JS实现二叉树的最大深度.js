### 解题思路

按层次遍历，只不过输出的不是 数组 而是层级

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
 * @return {number}
 */
var maxDepth = function(root) {
    let level = 0
    if (!root) return level

    const queue = [root]

    while (queue.length) {
        let len = queue.length
        
        while (len--) {
            const front = queue.shift()
            if (front.left) queue.push(front.left)
            if (front.right) queue.push(front.right)
        }

        level++
    }

    return level
};
```