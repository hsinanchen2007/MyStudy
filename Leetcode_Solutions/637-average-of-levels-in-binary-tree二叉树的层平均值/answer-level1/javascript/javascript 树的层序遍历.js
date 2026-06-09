### 解题思路
使用队列进行层序遍历

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
var averageOfLevels = function(root) {
    let temp = []
    let res = []
    let queue = []
    if (root) {
        let level = 0
        queue.push({ node: root, level })
        while (queue.length) {
            const item = queue.shift()
            const node = item.node
            const level = item.level
            if (level === temp.length) {
                temp.push([])
            }
            temp[level].push(node.val)
            node.left && queue.push({ node: node.left, level: level + 1 })
            node.right && queue.push({ node: node.right, level: level + 1 })
        }
    }
    if (temp.length) {
        for (let i = 0; i < temp.length; i++) {
            const arr = temp[i]
            const sum = arr.reduce((a, b) => a + b)
            const average = sum / arr.length
            res.push(average)
        }
    }
    return res
};
```