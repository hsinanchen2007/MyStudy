### 解题思路
本想着避免全量排序能快点，没想到，不是很快。代码也比较多，不过内存占用最少，所以贴出来做为一个参考吧。

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
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {number[]}
 */
var getAllElements = function (root1, root2) {
    let result = []
    let stack1 = []
    let stack2 = []
    let node1 = root1,
        node2 = root2
    let deal = function (node,stack) { 
        node = stack.pop()
        result.push(node.val)
        node = node.right
        return node
    }
    while (node1 || node2 || stack1.length || stack2.length) {
        while (node1) {
            stack1.push(node1)
            node1 = node1.left
        }
        while (node2) {
            stack2.push(node2)
            node2 = node2.left
        }
       
        if (stack1.length === 0 && stack2.length === 0) {
            //不处理
        } else if (stack1.length === 0) {
            node2=deal(node2,stack2)
        } else if (stack2.length === 0) {
            node1 = deal(node1, stack1)
        } else if (stack1[stack1.length - 1].val < stack2[stack2.length - 1].val) {
            node1 = deal(node1, stack1)
        } else {
            node2 = deal(node2, stack2)
        }
    }
    return result
};
```