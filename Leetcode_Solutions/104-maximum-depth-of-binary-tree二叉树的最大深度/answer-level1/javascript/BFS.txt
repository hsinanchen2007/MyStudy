```
var maxDepth = function(root) {
  if(!root) return 0
  let queue = [root], n=0
  while(queue.length) {
    let arr = []
    while(queue.length) {
      let cur = queue.shift()
      if(cur.left) arr.push(cur.left)
      if(cur.right) arr.push(cur.right)
    }
    n++
    queue = arr
  }
  return n
}
```
