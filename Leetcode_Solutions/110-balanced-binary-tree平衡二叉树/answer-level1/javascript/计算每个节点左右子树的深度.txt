利用一个额外的函数计算当前节点左右子树的最大深度，然后相加取绝对值
对每个节点都做此操作，递归遍历
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
   let leftDeep = maxDeep(root.left);    
   let rightDeep = maxDeep(root.right);
   let flag = Math.abs(leftDeep-rightDeep) > 1 ? false : true;
   return flag && isBalanced(root.left) && isBalanced(root.right);
};
var maxDeep = (root)=>{
   if(root == null){
       return 0
   }
    return Math.max(maxDeep(root.left),maxDeep(root.right))+1;
}
```