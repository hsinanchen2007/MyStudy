### 解题思路
递归和迭代

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
 * @param {number} val
 * @return {TreeNode}
 */
var insertIntoBST = function(root, val) {
    // if(root == null) return new TreeNode(val)
    // if(root.val < val) {
    //     root.right = insertIntoBST(root.right, val)
    // } else {
    //     root.left = insertIntoBST(root.left, val)
    // }
    // return root

    let cur = root
    while (cur) {
        if(val > cur.val) {
            if(cur.right == null) {
                cur.right = new TreeNode(val)
                return root
            } else {
                cur = cur.right
            }
        } else {
            if(cur.left == null) {
                cur.left = new TreeNode(val)
                return root
            } else {
                cur = cur.left
            }
        }
    }

    return root
};
```