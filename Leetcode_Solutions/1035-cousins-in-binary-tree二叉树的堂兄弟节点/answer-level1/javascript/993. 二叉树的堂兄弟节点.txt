### 解题思路

- 找到对应节点的高度和父节点
- 对比节点高度和各自父节点是否相同

⚠️注意：这里直接保存各自的父节点和各自的高度进行对比即可

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
    const getHeight = (root, prev, target, height) => {
        // 如果为空那么直接结束递归
        if (!root) {
            return 
        }
        // 如果找到 target，将 parent 和 height 存在对应的对象中
        // 同时结束递归
        if (root.val === target) {
            if (target === x) {
                first.parent = prev
                first.height = height
            } else {
                second.parent = prev
                second.height = height
            }
            return
        }
        // 递归左子树
        getHeight(root.left, root, target, height + 1)
        // 递归右子树
        getHeight(root.right, root, target, height + 1)
    }
    let first = {}
    let second = {}
    getHeight(root, null, x, 1)
    getHeight(root, null, y, 1)
    // 如果高度相同且两个节点的父节点不同，返回 true，否则返回 false
    return first.height === second.height && first.parent !== second.parent
};
```