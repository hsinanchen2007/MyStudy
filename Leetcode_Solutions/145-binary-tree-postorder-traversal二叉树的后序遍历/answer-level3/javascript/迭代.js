### 解题思路
迭代

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
var postorderTraversal = function(root) {
    if (!root) return []
    let stack1 = [root]
    let stack2 = []
    let res = []
    while (stack1.length > 0) {
        let item = stack1.pop()
        stack2.push(item)
        if (item.left) {
            stack1.push(item.left)
        }
        if (item.right) {
            stack1.push(item.right)
        }
    }
    while(stack2.length > 0) {
        let node = stack2.pop()
        res.push(node.val)
    }
    return res
};
```