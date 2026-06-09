一道简单BFS，写一个javascript题解
```
const queue = []
    const res = []
    let level = 0
    if (!root) {
        return res
    }
    queue.push([root])

    while(queue.length) {
        res[level] = []
        const nodeList = queue.shift()
        const nodes = nodeList.reduce((result, node) => {
          res[level].push(node.val)
          if (node.left) {
            result.push(node.left)
          }

          if (node.right) {
            result.push(node.right)
          }
          return result
        }, [])
        if (nodes.length) queue.push(nodes)
        level++
    }

    return res.reverse()
```
