### 解题思路
1. 有同学分享了递归解法，考虑性能采用 深度广先遍历 + 栈解法
2. 使用 js 数组 实现栈， 时间/空间复杂度表现不错
3. 多写几个测试例子，保证case执行正确 

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
 * @param {TreeNode} node
 * @return {boolean}
 */
var isSymmetric = function (node) {
    if (node === null) {
        return true;
    }
    const stack = [node.left, node.right];
    while (stack.length) {
        const left = stack.pop();
        const right = stack.pop();
        if (left === null && right === null) {
            continue;
        } else if (left === null || right === null) {
            return false;
        } else if (left.val === right.val) {
            stack.push(left.right || null);
            stack.push(right.left || null);
            stack.push(left.left || null);
            stack.push(right.right || null);
        } else {
            return false;
        }
    }
    return true;
};
```