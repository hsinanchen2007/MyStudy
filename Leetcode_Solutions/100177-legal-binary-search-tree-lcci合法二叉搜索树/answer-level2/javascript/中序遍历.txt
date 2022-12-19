### 解题思路
中序遍历的结果是递增的，如果出现非递增，就不是搜索树了。

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
    
  let result=true
  let lastVal=-Infinity

  function helper(root){
      if(!root||result===false) return
      helper(root.left)
      if(root.val<=lastVal) {
          result=false
          return
      }
      lastVal=root.val
      helper(root.right)
  }
  helper(root)
  return result
};
```