### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, left, right) {
 *      this.val = val;
 *      this.left = left;
 *      this.right = right;
 *  };
 */
/**
 * @param {Node} root
 * @return {Node}
 */
const treeToDoublyList = root => {

    if (!root) return null

    dummyRoot = {}, prev = dummyRoot // global variable
    dfs(root)

    dummyRoot.right.left = prev // circle
    prev.right = dummyRoot.right

    return dummyRoot.right
};

const dfs = node => {
    if (node) {
        dfs(node.left)

        node.left = prev
        prev.right = node
        prev = node

        dfs(node.right)
    }
};
```