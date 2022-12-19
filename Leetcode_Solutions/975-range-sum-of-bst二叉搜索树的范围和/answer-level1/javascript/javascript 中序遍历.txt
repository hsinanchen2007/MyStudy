### 解题思路
对于二叉搜索树，中序遍历就是从小到大的顺序

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
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
 var rangeSumBST = function(root, L, R) {
    const stack = []
    let node = root;
    let sum = 0
    while (stack.length > 0 || node !== null) {
        // 这里用当前节点node是否存在，简化代码，
        if (node) {
            stack.push(node);
            node = node.left
        } else {
            node = stack.pop();
            if (node.val >= L && node.val <= R) {
                sum += node.val
            }
            node = node.right;
        }
    }
    return sum
};
```