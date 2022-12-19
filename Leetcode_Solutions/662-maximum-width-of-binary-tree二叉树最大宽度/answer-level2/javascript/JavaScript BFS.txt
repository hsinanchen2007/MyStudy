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
 * @return {number}
 */
var widthOfBinaryTree = function(root) {
    if (!root) {
        return 0
    }
    const queue = [{ node: root, index: 1 }]
    let max = 1
    while (queue.length) {
        const len = queue.length
        // 这一层的长度为1不需要计算宽度
        if (len > 1) {
            const start = queue[0].index
            const end = queue[len - 1].index
            const width = end - start + 1
            max = Math.max(max, width)
        }
        for (let i = 0; i < len; i++) {
            const temp = queue.shift()
            const node = temp.node
            const index = temp.index
            // 层序遍历过程中，用index来维护节点索引，一个节点索引是index,那他的左孩子索引是index * 2,右孩子索引是index * 2 +1
            node.left && queue.push({ node: node.left, index: index * 2 })
            node.right && queue.push({ node: node.right, index: index * 2 + 1 })
        }
    }
    return max
};
```