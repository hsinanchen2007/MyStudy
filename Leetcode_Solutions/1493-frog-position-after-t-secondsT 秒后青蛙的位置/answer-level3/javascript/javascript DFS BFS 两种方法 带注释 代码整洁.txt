### 解题思路

第一步：建立树结构
第二步：DFS 或 BFS 遍历，判断是否能在 t 时间内到达 target 节点。 这里的 t 可以理解为树的深度或者跳跃的步数。

在使用 DFS 和 BFS 算法时，不管什么题目，先把 DFS 和 BFS 的完整框架写出来。然后在添加目标变量的计算或者添加约束条件判断是否剪枝

### 代码

方法一： DFS （推荐）

DFS 过程中可以通过系统堆栈记录部分数据，一定程度上可以遍历过程中的变量维护。

```javascript
/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} t
 * @param {number} target
 * @return {number}
 */
var frogPosition = function(n, edges, t, target) {
  let graph = Array(n + 1)
    .fill(0)
    .map(v => [])
  edges.forEach(edge => {
    let [from, to] = edge
    graph[from].push(to)
    graph[to].push(from)
  })
  let res = 0
  let visited = new Set([1])
  dfs(graph, 1, 1, 0)
  return res

  function dfs(graph, cur, radio, curDepth) {
    let children = graph[cur].filter(i => !visited.has(i))
    // 需要满足深度条件
    if (curDepth > t) return
    // 如果我们找到了 target, 此时需要满足 depth 刚好等于 t 或者此时无法继续跳了
    if (cur === target && (curDepth === t || !children.length)) {
        res = radio
        return true
    }

    let len = children.length
    for (let i = 0; i < len; i++) {
      visited.add(children[i])
      let find = dfs(graph, children[i], radio / len, curDepth + 1)
      visited.delete(children[i])
      if (find) return true
    }
  }
}
```

方法二： BFS

```javascript
var frogPosition = function(n, edges, t, target) {
  let graph = Array(n + 1)
    .fill(0)
    .map(v => [])
  // 建立树结构
  edges.forEach(edge => {
    let [from, to] = edge
    graph[from].push(to)
    graph[to].push(from)
  })
  // 队列中记录节点的 id 和 当前节点的概率
  let queue = [{ id: 1, radio: 1 }]
  let visited = new Set([1])

  let cur
  let depth = 0
  // 遍历的结束条件：需要满足遍历深度 depth <= t
  while (queue.length && depth <= t) {
    let levelLen = queue.length
    // 由于需要记录层数，所以需要一次遍历一层
    for (let j = 0; j < levelLen; j++) {
      // 从队列中取出一个节点，并判断是否满足结束条件
      cur = queue.shift()
      let children = graph[cur.id].filter(i => !visited.has(i))
      if (cur.id === target) {
        // 如果我们找到了 target, 此时需要满足 depth 刚好等于 t 或者此时无法继续跳了
        if (depth === t || !children.length) return cur.radio
      }

      // 向队列中添加新的节点，并标记已访问
      for (let i = 0; i < children.length; i++) {
        queue.push({ id: children[i], radio: cur.radio / children.length })
        visited.add(children[i])
      }
    }
    depth++
  }
  return 0
}
```