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
 * @param {number} sum
 * @return {boolean}
 */
var hasPathSum = function (root, sum) {
    var num = 0;
    var array = [];
    help(root, array, num)
    return array.indexOf(sum) >= 0
};

function help(root, array, num) {
    if (root === null) return false
    num = num + root.val
    if (root.left === null && root.right === null) {
        array.push(num);
    }
    if (root.left) help(root.left, array, num);
    if (root.right) help(root.right, array, num);
}

```
可以继续优化的地方就是 不用存在数组里再去找