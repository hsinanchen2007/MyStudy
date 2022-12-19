```
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
var isSymmetric = function(root) {
    if(!root) return true;
    let isMirror = (p, q) => {
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        
        return p.val === q.val && isMirror(p.left, q.right) && isMirror(p.right, q.left);
    }
    return isMirror(root.left, root.right);
};
```
