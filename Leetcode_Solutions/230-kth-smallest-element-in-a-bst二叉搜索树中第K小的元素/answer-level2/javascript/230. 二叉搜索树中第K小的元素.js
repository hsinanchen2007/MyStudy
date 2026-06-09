### 解题思路

- 中序遍历 ``二叉搜索树``
- 对 ``k`` 进行自减，直至 ``k === 0``，那么当前节点为第 ``k`` 小的元素

⚠️注意：``二叉搜索树`` 的中序遍历结果是有序的

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
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(root, k) {
    const helper = (root) => {
        if (!root) {
            return
        }
        helper(root.left)
        if (--k === 0) {
            target = root.val
            return
        }
        helper(root.right)
    }
    let target = null
    helper(root)
    return target
};
```