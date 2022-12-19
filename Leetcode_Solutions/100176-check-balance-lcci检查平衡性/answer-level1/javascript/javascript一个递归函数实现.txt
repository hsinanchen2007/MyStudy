### 解题思路
递归判断每个节点的左子树和右子树，遇到树深大于 1 的就算得到解。
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
   let result=true
   function helper(root){
       if(result ===false) return 0
       if(!root) return 0
       let left=helper(root.left)
       let right=helper(root.right)
       if(Math.abs(left-right)>1) result=false
       return Math.max(left,right)+1
   }
   helper(root)
   return result
};
```