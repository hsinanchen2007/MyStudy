### 解题思路
见注释

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
 * @return {number[]}
 */
var levelOrder = function(root) {
    var arr = []; // 存储结果集
    var list = [root]; // 辅助栈
    if (!root) return []; // 考虑特殊情况
    while(list.length) { //栈不空的时候
        var head = list.shift(); // 取栈首
        arr.push(head.val);
        if (head.left || head.right) {
            if (head.left) { // 如果有左子树，就把左子树入栈
                list.push(head.left);
            }
            if (head.right) { // 如果有右子树，就把右子树入栈
                list.push(head.right);
            }
        }       
    }
    return arr;
};
```