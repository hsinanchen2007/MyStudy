### 解题思路
暴力思路：初始化两个Map一个存depth，一个存每个节点的parent是谁
Map.set(key, value); value == Map.get(key)
中序遍历二叉树，将每一个节点的深度和父节点是谁分别存入两个Map中
最后判断两个 Map，深度一样 同时 parent不一样

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
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    var depth = new Map();
    var parents = new Map();

    function ifbrothers(root, parent){
    depth.set(root.val, parent == null ? 0 : depth.get(parent.val)+1)
    parents.set(root.val, parent)
    if(root.left)ifbrothers(root.left, root)
    if(root.right)ifbrothers(root.right, root)
}
    ifbrothers(root, null)
    return depth.get(x) == depth.get(y) && parents.get(x) != parents.get(y)
};

```