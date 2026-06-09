```
var rightSideView = function(root) {
  if(!root) return []
  const queue = [root]
  const res = []
  while(queue.length) {
    let len = queue.length
    // 处理完这一层的节点
    while(len) {
      const cur = queue.shift()
      // 如果是这一层的最后一个节点（也就是最右边的节点），放入res
      if(len === 1) {
        res.push(cur.val)
      }
      // 收集下一层节点
      if(cur.left) {
        queue.push(cur.left)
      }
      if(cur.right) {
        queue.push(cur.right)
      }
      len--
    }
  }
  return res
};
```
