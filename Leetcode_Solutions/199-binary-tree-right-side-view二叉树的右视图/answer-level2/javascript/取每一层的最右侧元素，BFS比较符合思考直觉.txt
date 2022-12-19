比较标准的bfs模板，树的广度优先搜索都可以用
```
var rightSideView = function(root) {
  if (root === null) return []
  let result = []
  let queue = [root]
  while (queue.length > 0) {
    let right
    let len = queue.length
    for (let i=0; i<len; i++) {
      let cur = queue.shift()
      right = cur.val
      cur.left && queue.push(cur.left)
      cur.right && queue.push(cur.right)
    }
    result.push(right)
  }
  return result
};
```
