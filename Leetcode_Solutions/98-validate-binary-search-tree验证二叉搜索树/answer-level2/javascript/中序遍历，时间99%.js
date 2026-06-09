### 解题思路

看了官方题解，发现可以利用中序遍历的顺序，果然速度很快
 * 利用中序遍历的读取顺序，只要当前val比上一个val大就可以了
 * 默认值为最小值

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
 * 利用中序遍历的读取顺序，只要当前val比上一个val大就可以了
 * 默认值为最小值
 * @param {TreeNode} root
 * @return {boolean}
 */
var isValidBST = function (root) {
    let prev = Number.MIN_SAFE_INTEGER;
    let res = true;
    inorder(root);
    return res;
    function inorder(node) {
        if (node !== null && res) {
            inorder(node.left);
            res = res && node.val > prev;
            prev = node.val;
            inorder(node.right);
        }
    }
};
```