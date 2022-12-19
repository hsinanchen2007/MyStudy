### 解题思路
dfs递归

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
var maxDepth = function(root) {
    if(!root)return 0;
    let max=1;
    (function dfs(root,deep=1){
        if(root){
            max =max>deep?max:deep;
            if(root.left)dfs(root.left,deep+1);
            if(root.right)dfs(root.right,deep+1); 
        }
    })(root);

    return max;
    

};
```