### 解题思路
执行用时 :
52 ms
, 在所有 JavaScript 提交中击败了
99.96%
的用户

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
var maxDepth = function(root, level) {
    // 根节点为null时的判定
    if(!root) {
        return 0
    }
    // 根节点时，设置深度为1
    if(!level) {
        level =  1
    }
    if(root.left && root.right) {
        // 双子树，取最大值
        return Math.max(
            // 层级加1
            maxDepth(root.left, level + 1),
            maxDepth(root.right, level + 1)
        )
    } else if(root.left){
        // 单子树
        return maxDepth(root.left, level + 1)
    } else if(root.right) {
        return maxDepth(root.right, level + 1)
    } else {
        // 叶子节点，或只有根节点时
        return level
    }
};
```