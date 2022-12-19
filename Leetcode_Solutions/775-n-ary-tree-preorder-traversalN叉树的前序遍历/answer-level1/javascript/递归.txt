
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
    if(!root) return [];
    let ans = [];
    (function(root) {
        ans.push(root.val);
        root.children.map((child) => arguments.callee(child))
    })(root)
    return ans;
};
```