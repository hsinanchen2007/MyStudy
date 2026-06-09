### 解题思路
使用map来缓存每一列的元素

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
 * @return {number[][]}
 */
var verticalOrder = function(root) {
    if (!root) {
        return []
    }
    const res = []
    const queue = [{ level: 0, node: root }]
    const map = new Map()
    while (queue.length) {
        const temp = queue.shift()
        const level = temp.level
        const node = temp.node
        if (!map.get(level)) {
            map.set(level, [])
        }
        const arr = map.get(level)
        arr.push(node.val)
        map.set(level, arr)
        node.left && queue.push({ level: level - 1, node: node.left })
        node.right && queue.push({ level: level + 1, node: node.right })
    }
    const mapArr = Array.from(map)
    mapArr.sort((a, b) => a[0] - b[0])
    mapArr.forEach(arr => {
        res.push(arr[1])
    })
    return res
};
```