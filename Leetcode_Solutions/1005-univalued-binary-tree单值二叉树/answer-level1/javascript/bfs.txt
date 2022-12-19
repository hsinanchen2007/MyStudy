### 解题思路
此处撰写解题思路

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
 * @return {boolean}
 */
var isUnivalTree = function(root) {

    let queue = [root]

    while (queue.length) {
        let node = queue.shift();
        if (node.val !== root.val) return 0
        
        if (node.left) queue.push(node.left)
        if (node.right) queue.push(node.right)
    }

    return 1
};
```