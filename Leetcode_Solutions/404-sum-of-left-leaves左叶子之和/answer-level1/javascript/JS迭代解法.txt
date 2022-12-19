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
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    if (!root) return 0
    let sum = 0
    let stack = []
    stack.push([root, false])   // 栈用于保存某节点及该节点是否为左子节点
    while (stack.length) {
        let [node, isLeft] = stack.pop()
        if (isLeft && !node.left && !node.right) sum += node.val    // 找到左子节点，累加
        if (node.left) stack.push([node.left, true])
        if (node.right) stack.push([node.right, false])
    }

    return sum
};
```