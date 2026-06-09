1、BFS遍历每一层节点，当有叶子节点（左右均可）时，说明有下一层，level+1，否则找到第一个无叶子节点的层级就是最小层数。

```javascript []
/*
 * @lc app=leetcode.cn id=111 lang=javascript
 *
 * [111] 二叉树的最小深度
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
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function (root) {
  if (!root) return 0;
  let level = 0;
  let queue = [root];

  while (queue.length) {
    level += 1;

    let len = queue.length;
    while (len--) {
      let node = queue.shift();
      if (!node.left && !node.right) {
        return level;
      }
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
  }

  return level;

};
// @lc code=end


```

![image.png](https://pic.leetcode-cn.com/c530ec96b12f65a03a8bc5f24ac52ec46294c7dac973e600ebd93723e9800767-image.png)

2、递归左右子树：
  - 当有叶子节点时，将深度+1，继续遍历左右子树，找到left和right最小值返回。
  - 当有左右其中之一时，其深度需要+1, 则需取left，right最大值。由于其中之一为0，可以直接相加
  - 当左右子数都为空时，返回，可直接包含在上一步中。
```javascript []
/*
 * @lc app=leetcode.cn id=111 lang=javascript
 *
 * [111] 二叉树的最小深度
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
 * @param {TreeNode} root
 * @return {number}
 */
var minDepth = function (root) {
  if(!root) return 0;
  let left = minDepth(root.left);
  let right = minDepth(root.right);

  return (left === 0 || right ===0) ? 1 + left + right : 1 + Math.min(left, right);
}
```