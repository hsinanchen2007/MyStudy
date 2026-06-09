### 解题思路
这里因为不同层级的输出在不同的数组内，所以这里依然是可以使用先序遍历递归实现

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
var levelOrder = function(root, arr, level) {
    if(!arr) arr = []
    if(!root) return arr
    if(!level) level = 0
    if(!arr[level]) arr[level] = []
    arr[level].push(root.val)
    if(root.children) {
        root.children.forEach(i => levelOrder(i, arr, level + 1))
    }
    return arr
};
```