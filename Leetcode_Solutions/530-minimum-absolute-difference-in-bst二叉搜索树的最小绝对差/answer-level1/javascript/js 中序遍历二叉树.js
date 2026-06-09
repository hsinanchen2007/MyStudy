![image.png](https://pic.leetcode-cn.com/8edf871f182f54429058a06fec97d59d8e440d43921b479d156c87e59410460f-image.png)

### 解题思路
```js
因为二叉搜索树的特点，每一个节点值都大于它的左节点，
并且小于它的右节点，所以只需要求相邻节点的最小差
```

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
 * @return {number}
 */

var getMinimumDifference = function(root) {
  function recursion(node) {
    if (node === null) return ;
    recursion(node.left);
    if (last !== null) {
      ans = Math.min(ans, node.val - last);
    }
    last = node.val;
    recursion(node.right);
  }
  
  let ans = Infinity, last = null;
  
  recursion(root);
  
  return ans;
};
```