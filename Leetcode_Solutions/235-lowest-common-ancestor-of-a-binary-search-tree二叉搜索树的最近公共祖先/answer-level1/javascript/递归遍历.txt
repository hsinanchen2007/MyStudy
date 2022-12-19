### 解题思路
寻找二叉搜索树的公共节点，比普通的树方便的是有大小规律，不用全部走一遍
判断p  q 的值分别在root的哪里边，就可以调用左子树或者右子树

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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function(root, p, q) {
    if(root == null){return root}
    if(p.val < root.val && root.val > q.val){
       return lowestCommonAncestor(root.left, p, q);
    }
    if(p.val > root.val && root.val < q.val){
       return lowestCommonAncestor(root.right, p, q);
    }
    return root;
};
```