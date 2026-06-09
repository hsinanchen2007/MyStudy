### 解题思路 JS迭代法
JS迭代法

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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    if (!root) return []
    let res = []
    let stack = []
    stack.push([root, root.val.toString()]) // 栈用于保存某个节点node及根节点至该节点的路径
    while (stack.length) {
        let [node, path] = stack.pop()
        if (!node.left && !node.right) res.push(path)   // node没有左右子节点，因此node为叶子节点，把路径加入结果
        if (node.right) stack.push([node.right, path + '->' + node.right.val])  // 构建路径
        if (node.left) stack.push([node.left, path + '->' + node.left.val]) // 构建路径
    }
    return res
};
```