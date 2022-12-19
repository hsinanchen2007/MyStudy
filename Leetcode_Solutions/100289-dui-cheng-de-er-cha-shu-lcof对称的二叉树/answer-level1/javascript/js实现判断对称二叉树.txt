### 解题思路
此处撰写解题思路

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
var isSymmetric = function(root) {
    if(root===null ||(root.left===null && root.right===null))return true;
    else if(root.left===null || root.right===null)return false;
    if(root.left.val != root.right.val) return false;
    function dfs(left,right){
        if(left===null &&right === null)return true;
        else if(left===null || right === null)return false;
        if(left.val !==right.val)return false;
        return dfs(left.left,right.right) && dfs(left.right,right.left);
    }
    return dfs(root.left,root.right);

};
```