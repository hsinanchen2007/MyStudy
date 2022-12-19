战胜了14.41%的用户 ( ╯-_-)╯┴—┴
不过至少论行数应该可以战胜90% (￣^￣)

```javascript
var levelOrder = function(root) {
  return root === null ? [] : bfs([root], [])
 
  function bfs (nodes, result) {
    if (nodes.length === 0) return result
    result.push([...nodes.map(node => node.val)])
    return bfs(nodes.reduce((p, c) => (p.push(c.left, c.right), p), []).filter(Boolean), result)
  }
};
```