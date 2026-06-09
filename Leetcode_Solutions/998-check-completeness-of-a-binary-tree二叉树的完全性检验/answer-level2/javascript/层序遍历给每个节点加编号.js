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
var isCompleteTree = function(root) {

    if (!root) return 1

    let queue = [[root, 1]], count = 0
    while (queue.length) {
        let obj = queue.shift(), 
            node = obj[0], n = obj[1]
            
        if (n !== ++count) return 0

        if (node.left) queue.push([node.left, n << 1])
        if (node.right) queue.push([node.right, (n << 1) + 1])
    }

    return 1
};
```