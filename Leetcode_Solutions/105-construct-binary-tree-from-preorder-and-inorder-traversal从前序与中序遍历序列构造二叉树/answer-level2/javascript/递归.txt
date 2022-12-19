### 解题思路
前序遍历数组的第一个值即为当前节点的值，

在中序遍历中，该值左边的元素构成左子树，右边的元素构成右子树。

递归实现。

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
var buildTree = function(preorder, inorder) {
    const build = (inorder) => {
        if (!inorder || !inorder.length) return null;
        const temp = preorder.shift(), mid = inorder.indexOf(temp);
        const root = new TreeNode(temp);
        root.left = build(inorder.slice(0, mid));
        root.right = build(inorder.slice(mid+1));
        return root;
    }
    return build(inorder);
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)