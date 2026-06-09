![image.png](https://pic.leetcode-cn.com/c5f191079f3d0c0d247a10d52ebaa09d10f2324f1940c2f1baebef98339da8b7-image.png)

### 解题思路
```js
递归判断一旦有某个节点的左右子树的深度差大于1，直接判断结果为 false
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
  let ans = true;
  
  function isbalance(node) {
    if (ans === true) {
      if (node === null) return 0;
    
      let left = isbalance(node.left),
          right = isbalance(node.right);

      if (Math.abs(left - right) > 1) ans = false;

      return Math.max(left, right) + 1;
    }
  }
  
  isbalance(root);
  
  return ans;
};
```