### 解题思路
执行用时 :
64 ms
, 在所有 JavaScript 提交中击败了
96.31%
的用户
内存消耗 :
37.2 MB
, 在所有 JavaScript 提交中击败了
82.74%
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
var minDepth = function(root, level) {
    // 根节点为null时的判定
    if(!root) {
        return 0
    }
    // 根节点时，设置深度为1
    if(!level) {
        level =  1
    }
    if(root.left && root.right) {
        // 双子树，取最小值
        return Math.min(
            // 层级加1
            minDepth(root.left, level + 1),
            minDepth(root.right, level + 1)
        )
    } else if(root.left){
        // 单子树
        return minDepth(root.left, level + 1)
    } else if(root.right) {
        return minDepth(root.right, level + 1)
    } else {
        // 叶子节点，或只有根节点时
        return level
    }
};
```