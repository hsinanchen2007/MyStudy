### 解题思路
js

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
var inorderTraversal = function(root) {
    let result = [];

    //暂存
    let temp = [];

    //检查的node
    let node = root;

    while (node !== null || temp.length > 0) {

        if (node !== null) {
            temp.push(node);
            node = node.left;
        } else {
            node = temp.pop()
            result.push(node.val);
            node = node.right
        }
    }
    return result;
};
```