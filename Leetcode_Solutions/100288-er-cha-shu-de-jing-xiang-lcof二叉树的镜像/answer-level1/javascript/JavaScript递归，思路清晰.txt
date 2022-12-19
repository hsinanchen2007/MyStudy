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
 * @return {TreeNode}
 */
var mirrorTree = function(root) {
    func(root);
    return root;
};

function func(root){
    if(!root) return;
    var tmp = root.left;
    root.left = root.right;
    root.right = tmp;
    func(root.left);
    func(root.right);
}
```