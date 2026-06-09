### 解题思路
分别定义一个栈和一个数组，先将左子树压入到栈中，直到左子树为null,然后开始弹栈，将值push到数组中，再反过来将右子树压入到栈中，
再开始弹栈，将结果push到数组中。

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

const inorderTraversal = function(root) {
    const result = []
    const stack = []
    while(stack.length || root) {
        if(root) {
            stack.push(root)
            root = root.left
        } else {
            const node = stack.pop()
            result.push(node.val)
            root = node.right
        }
    }
    return result
};
```