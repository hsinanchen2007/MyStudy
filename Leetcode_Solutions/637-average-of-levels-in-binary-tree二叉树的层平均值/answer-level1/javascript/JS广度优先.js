```javascript []
const averageOfLevels = (root) => {
    let queue = [root], result = [], arr = [], sum = 0, length = 1
    while (queue.length) {
        let node = queue.shift()
        sum += node.val
        node.left && arr.push(node.left)
        node.right && arr.push(node.right)
        if (queue.length === 0) {
            result.push(sum/length)
            queue = arr
            length = queue.length
            arr = []
            sum = 0
        }
    }
    return result
};
```
