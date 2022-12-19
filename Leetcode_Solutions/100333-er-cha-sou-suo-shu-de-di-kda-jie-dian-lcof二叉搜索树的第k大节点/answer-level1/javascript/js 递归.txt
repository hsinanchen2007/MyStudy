![image.png](https://pic.leetcode-cn.com/17a43625708e006d49effb72544dbfd5a48775dd28e8c34a1311ef965a8f556e-image.png)

### 解题思路
```js
二叉树的中序遍历 右 - 根 - 左，放到一个数组中
再返回数组的第 k 大的数
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
 * @param {number} k
 * @return {number}
 */

var kthLargest = function(root, k) {
  let ans = [];
  
  function largest(node) {
    if (node === null) return ;

    largest(node.right);
    ans.push( node.val );
    largest(node.left);
  }
  largest(root);
  
  return ans[k - 1];
};
```