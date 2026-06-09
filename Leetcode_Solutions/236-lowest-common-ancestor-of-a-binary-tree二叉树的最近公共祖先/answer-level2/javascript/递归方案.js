### 解题思路
牢记双层递归的遍历顺序问题
然后重点就是左孩子是null，直接返回右边的孩子值，如果是null，也会返回，然后继续回溯，再向上找父节点
如果左右都有值，那当前节点就是公共祖先节点
本次操作的缺点，会把整颗树遍历完。

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
// let isEnd = false;
var lowestCommonAncestor = function(root, p, q) {
    // if(isEnd){return}
    if(root ==null || root == p || root == q) {return root}

    let leftNode = lowestCommonAncestor(root.left, p , q);
    let rightNode = lowestCommonAncestor(root.right, p, q);

    if(leftNode ==null) {return rightNode}
    if(rightNode ==null) {return leftNode}
    if(leftNode !=null && rightNode !=null)
    return root;
};
```