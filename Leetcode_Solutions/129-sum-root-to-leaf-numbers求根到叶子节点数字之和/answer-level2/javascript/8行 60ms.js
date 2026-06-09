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
var sumNumbers = function(root, number=0) {
    if(root === null){
        return 0;
    }else if(root.left === null && root.right === null){
        return number + root.val;
    }else {
        number = (number + root.val)*10;
        return sumNumbers(root.left, number) + sumNumbers(root.right, number);
    }
};
```