### 解题思路
递归
坡度 = sum（左子树.val） - sum（右子树.val） 

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
var findTilt = function(root) {
    var result = 0;
    function sumTreeVal(root){
        if(!root) {return 0}
        let left = sumTreeVal(root.left)
        let right = sumTreeVal(root.right);
        result = result + Math.abs(left-right);
        return left + right + root.val;
    }
    sumTreeVal(root);
    return result
};
```