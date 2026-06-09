### 解题思路
此处撰写解题思路
1.过滤树的叶子节点。
2.结合先序遍历和中序遍历划分左右子树，找出根节点在中序遍历中的索引。
3.通过slice切片划分出左右子树，进行递归求解。
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
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */

var buildTree = function (preorder, inorder) {
        if (!preorder.length || !inorder.length) {
            return null;
        }
        const nodevalue = preorder[0];
        let nodeValueIndex = inorder.indexOf(nodevalue);
        const node = new TreeNode(nodevalue);
        node.left = buildTree(preorder.slice(1, nodeValueIndex + 1), inorder.slice(0, nodeValueIndex));
        node.right = buildTree(preorder.slice(nodeValueIndex + 1), inorder.slice(nodeValueIndex + 1))
        return node;
    };

```