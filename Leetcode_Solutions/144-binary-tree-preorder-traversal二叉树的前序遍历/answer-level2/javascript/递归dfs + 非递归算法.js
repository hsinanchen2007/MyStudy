### 解题思路
此处撰写解题思路

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
 * @return {number[]}
 */
const preorderTraversal = (root) => { // 非递归算法

    let ans = []
    if (!root) return ans

    let stack = [root] // aux === auxiliary 辅助栈

    while (stack.length) {
        let node = stack.pop()
        ans.push(node.val)

        if (node.right) stack.push(node.right)
        if (node.left) stack.push(node.left)
    }

    return ans
};

const preorderTraversal2 = (root) => { // 递归算法

    let ans = []
    if (!root) return ans

    dfs(root, ans)
    return ans
};

const dfs = (node, arr) => { // Depth-First-Search 深度优先搜索
    if (node) {
        arr.push(node.val)
        dfs(node.left, arr)
        dfs(node.right, arr)
    }
}
```