### 解题思路
层序遍历过程中，用index来维护节点索引，一个节点索引是index,那他的左孩子索引是index * 2,右孩子索引是index * 2 +1

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
 * @return {boolean}
 */
var isCompleteTree = function(root) {
    if (!root) {
        return true
    }
    const queue = [{ node: root, index: 1 }]
    let count = 0
    while (queue.length) {
        const temp = queue.shift()
        const node = temp.node
        const index = temp.index
        // 用来判断索引位置节点是否存在，如果index !== ++count代表左右子树层级相差超过1层，或者最后一层没有左节点却有右节点
        if (index !== ++count) {
            return false
        }
        // 层序遍历过程中，用index来维护节点索引，如果根节点index为1，那么一个节点索引是index,那他的左孩子索引是index * 2,右孩子索引是index * 2 +1
        node.left && queue.push({ node: node.left, index: index * 2 })
        node.right && queue.push({ node: node.right, index: index * 2 + 1 })
    }
    return true
};
```