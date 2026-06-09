
1、 自顶向下递归
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
var isBalanced = function(root) {
    if(root === null) return true;
    return Math.abs(height(root.left) - height(root.right)) < 2 && isBalanced(root.left) && isBalanced(root.right);
};
const height = function(node) {
    if(node === null) return -1;
    return 1+ Math.max(height(node.left),height(node.right));
}

```
时间复杂度: O(nlogn),深度为n的节点，height会被调n次。
空间复杂度: O(n)如果树完全倾斜，递归栈可能包含所有节点。

2、自底向上递归
方法一计算height 存在大量冗余。每次调用height 时，要同时计算其子树高度。但是自底向上计算，每个子树的高度只会计算一次。可以递归先计算当前节点的子节点高度，然后再通过子节点高度判断当前节点是否平衡，从而消除冗余。
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
class TreeInfo {
    constructor(height, balanced) {
        this.height = height;
        this.balanced = balanced;
    }
}
const isBalancedTreeHelper = function(root) {
    if(root === null) return new TreeInfo(-1, true);
    // 左树或又树不平衡则都整个树都不平衡
    let left = isBalancedTreeHelper(root.left);
    if (!left.balanced) { 
      return new TreeInfo(-1, false);
    }
    let right = isBalancedTreeHelper(root.right);
    if (!right.balanced) {
      return new TreeInfo(-1, false);
    }

    if (Math.abs(left.height - right.height) < 2) {
      return new TreeInfo(Math.max(left.height, right.height) + 1, true);
    }
    // 大于1的情况返回false
    return new TreeInfo(-1, false);
}
var isBalanced = function(root) {
    return isBalancedTreeHelper(root).balanced;
};

```
时间复杂度: O(n),计算每棵子树的高度和判断平衡操作都在恒定时间内完成。
空间复杂度: O(n)如果树完全倾斜，递归栈可能包含所有节点。