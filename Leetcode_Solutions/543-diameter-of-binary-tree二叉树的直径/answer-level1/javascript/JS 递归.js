### 解题思路

![image.png](https://pic.leetcode-cn.com/926678e087b575cce51e3646aad58bdfa4a39262b11fddef22a22fbd79c502b6-image.png)

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
var diameterOfBinaryTree = function(root) {
    if (!root) return 0;
    let res = 0;
    function check(node) {
        if (!node) {
            return -1;
        } else {
            let leftLen = check(node.left) + 1, rightLen = check(node.right) + 1;
            res = Math.max(res, leftLen + rightLen);
            return Math.max(leftLen, rightLen);
        }
    }
    check(root);
    return res;
};
```