### 解题思路

> 前序遍历，判断目标节点存在？入栈，判断当前节点的val是否为偶数，判断当前节点的左子树，右子树存在？，把左子树的子节点，右子树的子节点存入oddResult中，oddResult求和

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
var sumEvenGrandparent = function(root) {
    let stack = []
    let oddResult = []
    let target = root
    let count = 0
    while (target || stack.length > 0) {
        while (target) {
            if (target.val % 2 === 0) {
                let { left: leftChild, right:rightChild } = target
                if (leftChild) {
                    if (leftChild.left) {
                        oddResult.push(leftChild.left.val)
                    }
                    if (leftChild.right) {
                        oddResult.push(leftChild.right.val)
                    }
                }
                if (rightChild) {
                    if (rightChild.left) {
                        oddResult.push(rightChild.left.val)
                    }
                    if (rightChild.right) {
                        oddResult.push(rightChild.right.val)
                    }
                }
            }
            stack.push(target)
            target = target.left
        }
        target = stack.pop()
        target = target.right
    }
    for (let i = 0; i < oddResult.length; i++) {
        count+= oddResult[i]
    }
    return count
};
```