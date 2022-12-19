### 解题思路

很简单，跟循环解法逻辑一致。递归接收两个景象节点，如果镜像节点值都为null，返回true，如果只有一个值，或者两个节点的val 不一致，返回false

判断景象节点的逻辑：node1.left & node2.right | node1.right & node2.left

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
var isSymmetric = function(root) {
    if (!root) return true

    const loop = (node1, node2) => {
        if (!node1 && !node2) return true
        if (!node1 || !node2 || node1.val !== node2.val) return  false
        return loop(node1.left, node2.right) && loop(node1.right, node2.left)
    }

    return loop(root.left, root.right)
};
```