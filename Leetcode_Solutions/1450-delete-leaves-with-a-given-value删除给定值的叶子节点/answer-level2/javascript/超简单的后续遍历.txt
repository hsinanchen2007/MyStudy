### 解题思路
对这种删除类的题，就记住一点，后续遍历，处理完子树再处理当前结点。

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
 * @param {number} target
 * @return {TreeNode}
 */
var removeLeafNodes = function(root, target) {
    if(!root) return null
    root.left=removeLeafNodes(root.left,target)
    root.right=removeLeafNodes(root.right,target)
    if(!root.left&&!root.right){
        if(root.val===target) return null
    }
    return root

};
```