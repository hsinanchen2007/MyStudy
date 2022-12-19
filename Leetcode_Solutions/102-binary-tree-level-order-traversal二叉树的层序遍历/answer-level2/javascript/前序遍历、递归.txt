### 解题思路
前序遍历、递归即可

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
 * @return {number[][]}
 */
var levelOrder = function(root, arr, level) {
    // 递归初始化
    if(!arr) arr = []
    if(!root) return arr
    if(!level) level = 0
    if(!arr[level]) arr[level] = []
    // 输出当前节点信息
    arr[level].push(root.val)
    // 开始递归子数组
    levelOrder(root.left, arr, level + 1)
    levelOrder(root.right, arr, level + 1)
    // 结束返回
    return arr
};
```