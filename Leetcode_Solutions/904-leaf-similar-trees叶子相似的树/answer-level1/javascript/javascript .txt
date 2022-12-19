利用遍历定义三个两个函数，左和右， 然后根据节点去分别遍历子节点

```
/*
 * @lc app=leetcode.cn id=872 lang=javascript
 *
 * [872] 叶子相似的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function (root1, root2) {
  return helper(root1).join('') === helper(root2).join('')
};

var helper = function (root) {
  return [].concat(helperLeft(root), helperRight(root))
}

var helperLeft = function (root) {
  let value
  if (root.left) {
    value = helper(root.left)
  }
  if (root.val && !root.left && !root.right) {
    value = root.val
  }
  return value
}

var helperRight = function (root) {
  let value
  if (root.right) {
    value = helper(root.right)
  }
  if (root.val && !root.left && !root.right) {
    value = root.val
  }
  return value
}
// @lc code=end


```
