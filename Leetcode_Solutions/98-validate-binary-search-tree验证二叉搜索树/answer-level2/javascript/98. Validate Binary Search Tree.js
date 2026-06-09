### 解题思路
这个是判断BST是否有效的一道题，本来的思路只考虑到了子树及相关叶子节点的大小问题，没有意识到BST指的是左子树上的节点都小于根结点，右子树上的节点都大于根结点。根据官方题解第一种做出该道题，其他两种待实现。用higher，lower记录上一个节点，保证了逐级的大小关系即能保证整棵树是BST
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
var isValidBST = function(root) {
    return helper(root, null, null)
    function helper(node, lower, higher) {
        if (node === null) return true
        let val = node.val
        if (lower!==null && node.val <= lower) return false
        if (higher!==null && node.val >= higher) return false
        if (!helper(node.right, val, higher)) return false
        if (!helper(node.left, lower, val)) return false
        return true
    }
    
};
```