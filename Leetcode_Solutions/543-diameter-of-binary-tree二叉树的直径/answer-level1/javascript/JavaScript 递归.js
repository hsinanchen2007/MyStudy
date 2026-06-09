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
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
    //过程中的最大路径
    var max = 0;
    //遍历结点，求当前结点高度
    var diameterOfBinaryTree1 = function(root){
        if(root === null) return 0;
        //左子树高度
        var leftlen = diameterOfBinaryTree1(root.left);
        //右子树高度
        var rightlen = diameterOfBinaryTree1(root.right);
        //当前结点的最大直径
        max = max > leftlen + rightlen ? max : leftlen + rightlen;
        //返回当前树的高度
        return leftlen > rightlen ? leftlen + 1 : rightlen + 1;
    }
    diameterOfBinaryTree1(root);
    return max;
};
```