![image.png](https://pic.leetcode-cn.com/b0b0374c4bda4b92a5aec0ec7c4fc656f124601d6ef5085567ab47c8b5a8545d-image.png)

### 解题思路
```js
自底向上：
思路：
helper函数中做的事情：
1.返回当前树节点的高度，如果左子树比较高，那么左子树高度 + 1 为它的高度
  否则，右子树高度 + 1 为它的高度
2.每次判断当前树节点的左右子树的高度差是否超过 1，如果超过 1，返回 false

小优化：在 helper 函数中加了一行判断 `if (ans === true)`，意思即为：
如果 `ans === false` 了，那么我们已经找打了不平衡的树节点，就不需要再继续执行递归了，
这是终止递归函数的一种方式，否则，我们已经找到不平衡的节点，但还是继续递归去查找和计算，
这些时间是无用的花费。
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
 * @return {boolean}
 */

var isBalanced = function(root) {
  function helper(node) {
    if (ans === true) {
      if (!node) return 0;
      let left = helper(node.left) + 1,
        right = helper(node.right) + 1;

      if (Math.abs(left - right) > 1) ans = false;

      return Math.max(left, right);
    }
  }
  
  let ans = true;
  helper( root );
  
  return ans;
}

/*
  自顶向下：80ms
  思路：
  
  两个递归方法：
  1.递归判断当前树的左右子树的高度差是否小于 1
  2.递归获取当前树的高度
  
  两个递归的终止条件：当前树节点为 null
*/
// var isBalanced = function(root) {
//   function height(node) {
//     if (node === null) return 0;
//     return Math.max(height(node.left), height(node.right)) + 1;
//   }
  
//   if (root === null) return true;
//   return isBalanced(root.left) && isBalanced(root.right) &&
//     Math.abs( height(root.left) - height(root.right) ) < 2;
  
//   return isBalanced(root);
// };
```