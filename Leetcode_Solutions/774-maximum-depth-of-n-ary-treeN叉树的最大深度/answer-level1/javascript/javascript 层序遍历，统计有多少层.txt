### 解题思路
层序遍历

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number}
 */
var maxDepth = function(root) {
    if (!root) {
        return 0
    }
    let stack = [{ node: root, level: 1 }]
    let max = 1
    while (stack.length) {
        const temp = stack.shift()
        const node = temp.node
        const level = temp.level
        max = Math.max(level, max)
        if (node.children && node.children.length) {
            for (let i = 0; i < node.children.length; i++) {
                stack.push({node: node.children[i], level: level + 1})
            }
        }
    }
    return max
};
```