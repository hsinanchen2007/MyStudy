### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * // Definition for a Node.
 * function Node(val, children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */
/**
 * @param {Node} root
 * @return {number[]}
 */
var preorder = function(root) {
    const res = []
    if (root) {
        const temp = [root]
        while (temp.length) {
            const node = temp.pop()
            res.push(node.val)
            for (let i = node.children.length - 1; i >= 0 ; i--) {
                temp.push(node.children[i])
            }
        }
    }
    return res
};
```