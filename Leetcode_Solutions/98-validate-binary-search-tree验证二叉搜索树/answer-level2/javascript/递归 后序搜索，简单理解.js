### 解题思路
 如果一个树是bst
 * 那么他的每个节点n的 n.left也是一个bst, n.right也是一个bst
 * 并且n.val > n.left.max, n.val < n.right.min

min max方法在递归调用后，确定bst后使用min max方法
max空节点返回最小值，min空节点返回最大值，保证null的成立
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
 * 如果一个树是bst，那么他的每个节点n的 n.left也是一个bst, n.right也是一个bst
 * 并且n.val > n.left.max, n.val < n.right.min
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function(root) {
    if(root === null) return true;

    return isValidBST(root.left) && isValidBST(root.right) && root.val > maxVal(root.left) &&
    root.val < minVal(root.right);
};

/**
 * 找出一棵bst的max
 * 最右边的值
 * @param {TreeNode} root 
 */
function maxVal(root) {
    if(root === null) return Number.MIN_SAFE_INTEGER;
    if(root.right) return maxVal(root.right);
    else return root.val;
}
/**
 * 找出一棵bst的min
 * 最左边的值
 * @param {TreeNode} root 
 */
function minVal(root) {
    if(root === null) return Number.MAX_SAFE_INTEGER;
    if(root.left) return maxVal(root.left);
    else return root.val;
}
```