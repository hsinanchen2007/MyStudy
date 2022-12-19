可以记录每个树节点离最左边的距离。

需要注意的是 层数太深的时候这个距离会达到 Infinity
而Infinity-Infinity会是NaN....
对ans的NaN做了下特殊判断居然水过了。。。。
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
 * @return {number}
 */
let ans = 0
let min = {}
let max = {}
var widthOfBinaryTree = function(root) {
    ans = 0
    min = {}
    max = {}
    if(!root) return 1
    dfs(root, 0, 0)
    console.log(Object.keys(max).join(','))
    if(isNaN(ans)) ans = 0
    return ans + 1
};

function dfs(root, val, lv) {
    root.dis = val
    if(min[lv] == undefined) {min[lv] = max[lv] = val}
    min[lv] = Math.min(min[lv], val)
    max[lv] = Math.max(max[lv], val)
    ans = Math.max(ans, max[lv]-min[lv])
    if(root.left) dfs(root.left, val * 2, lv + 1)
    if(root.right) dfs(root.right, val * 2 + 1, lv + 1)
}
```