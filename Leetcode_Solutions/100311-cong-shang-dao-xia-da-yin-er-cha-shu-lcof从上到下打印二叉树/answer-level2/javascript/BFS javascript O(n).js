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
 * @return {number[]}
 */
var levelOrder = function(root) {
    if(root == null) return []
    let queue = [root]
    let res = []
    while (queue.length > 0) {
        let node = queue.shift()
        res.push(node.val)
        if(node.left){
            queue.push(node.left)
        }
        if(node.right) {
            queue.push(node.right)
        }
    }
    return res
};
```