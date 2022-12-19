```js
var leastInterval = function(tasks, n) {
  const o = {}
  tasks.forEach(key => {
    if (o[key]) {
      o[key] += 1
    } else {
      o[key] = 1
    }
  })
  const Q = []
  while (1) {
    const keys = Object.keys(o)
    const q = []
    if (keys.length === 0) { break }
    keys.sort((a, b) => o[b] - o[a]) // 大到小排序，先执行任务数目较多的任务
    for (let i = 0; i <= n; i++) {
      const fkey = keys.shift()
      if (typeof fkey !== 'undefined') {
        q.push(fkey)
        if (o[fkey] <= 1) {
          delete o[fkey]
        } else {
          o[fkey] -= 1
        }
      } else {
        break
      }
    }
    if (q.length < n + 1) {
      Q.push(...q.join('').padEnd(n + 1, '-').split(''))
    } else {
      Q.push(...q)
    }
  }
  const queue = Q.join('').replace(/-+$/g, '')
  return queue.length
}
```
