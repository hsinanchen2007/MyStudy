### 解题思路
使用队列进行广度优先遍历

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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    if (!root) return [];
    let queue = [root];
    let ans = [];
    while(queue.length) {
        let level = [];
        let len = queue.length;
        for (let i = 0; i < len; i++) {
            let current = queue.shift();
            level.push(current.val);
            if (current.children && current.children.length > 0) {
                queue.push(...current.children);
            }
        }
        ans.push(level);
    }
    return ans;
};
```