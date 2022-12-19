### 解题思路
问题可以看做为求每个节点 左右子树高度的和的最大值。

那么问题就可以分两步进行

1. 遍历整个二叉树所有节点
2. 求每个节点的左右子树高度和，返回最大的

其中左（右）子树的高度为其左（右）节点中子树高度的最大值



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
    let result = 0
    function walk(root) {
        let total = 0,left = 0 , right = 0 
        if(!root) {
            return -1
        }
        if (root.left) {
            left = walk(root.left) + 1
        }
        if (root.right) {
            right = walk(root.right)+ 1
        }
         total += left + right 
        result = Math.max(result,total)
        return Math.max(left,right)
    }
    walk(root)
    return result
};
```