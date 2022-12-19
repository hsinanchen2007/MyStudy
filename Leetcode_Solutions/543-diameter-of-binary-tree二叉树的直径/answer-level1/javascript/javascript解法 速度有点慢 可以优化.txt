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
    let max = 0
    const depth = (root) => {
        if(!root) return 0
        else {
          const leftDepth = depth(root.left),
              rightDepth = depth(root.right)

          const childDepth = leftDepth > rightDepth ? leftDepth : rightDepth

          return childDepth + 1
          //根节点不为空高度至少为1
      }
    }
    const digui = (root) => {
        if(root) {
            max = Math.max(depth(root.left) + depth(root.right), max)
            if(root.left) {
              digui(root.left)
            }
            if(root.right) {
              digui(root.right)
            }
        }
    }
    if(!root) return 0
    digui(root)
    return max
};
```