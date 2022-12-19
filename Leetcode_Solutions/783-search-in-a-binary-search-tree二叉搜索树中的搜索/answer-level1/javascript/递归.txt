### 解题思路
二叉树 本来就是左小右大, 判断当前节点的值是否等于val,等于就直接返回 大于就取左边 继续递归, 小于就去右边 继续递归, 如果到最后还没有就直接返回null

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
 * @param {number} val
 * @return {TreeNode}
 */
var searchBST = function(root, val) {
    if(!root) return null
    if(root.val === val){
      return root
    } else if(root.val > val){
      return searchBST(root.left,val)
    } else if(root.val < val){
      return searchBST(root.right,val)
    }
    return null
};
```