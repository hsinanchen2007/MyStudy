### 解题思路
深度优先遍历，很简单的一道题
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
    function checkAndDeep(root){
        if(root == null){
            return {isBal: true, deep: 0};
        }
        let left = checkAndDeep(root.left);
        let right = checkAndDeep(root.right);
        return {
            isBal: (Math.abs(left.deep - right.deep) <= 1) && left.isBal && right.isBal, 
            deep:(Math.max(left.deep, right.deep) + 1)
            }
    }
    return checkAndDeep(root).isBal;
};
```