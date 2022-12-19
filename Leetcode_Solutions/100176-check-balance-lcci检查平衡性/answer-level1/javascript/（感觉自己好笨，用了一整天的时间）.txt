### 解题思路
通过计算两个节点的深度，然后相减，结果小于等于1的时候，才会进行下一次递归，否则就返回undefined，

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
    if(root == null){
        return true;
    }
    var result1 = deep(root);
    if(result1){
        return true;
    }
    return false;
};

function deep(root){
    
    if(root == null){
        return 0;
    }
    var left = Math.abs(deep(root.left));
    var right = Math.abs(deep(root.right));
    var f = Math.abs(left-right);
    if(f <= 1){
        return Math.max(left,right)+1;
    }
    
}
```