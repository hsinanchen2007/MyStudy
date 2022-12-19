### 解题思路
![image.png](https://pic.leetcode-cn.com/2f68fc02dde205cb75beb95d01e64ad7434774c11884c2a4eb07393e80ad585e-image.png)
递归加三元符，行数少的一批。

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
var maxDepth = function (root) {
    if (!root) return 0;

    if (!root.left && !root.right) {
        return 1;
    } else {
        return 1 + Math.max(root.left ? maxDepth(root.left) : 0, root.right ? maxDepth(root.right) : 0);
    }
};
```