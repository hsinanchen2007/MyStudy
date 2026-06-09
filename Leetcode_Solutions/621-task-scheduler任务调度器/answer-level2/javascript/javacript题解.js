### 解题思路

大家好，我是 17

原理官方讲的很好了，我直接写下处理步骤。

1. 找出任务数量最大的任务 T，假设数量为 count ,则单把这个任务执行完需要的时间至少为 `(count-1) * (n+1)+1`
2. 看看数量为 count的任务还有几个，有几个，需要的时候就加几。
3. 看算出的时间和任务长度哪个长（因为每个任务的执行时间是1）哪个长取哪个

显然数量最多的任务用的时候最多，其它的任务可以用来填空。填不满，那就以任务T的执行时间为准，填了后还有任务，说明执行所有的任务不会有暂停，则数组的长度就是答案。

有一个特殊的就是最大数量的任务有多个，因为填空后还多出一个，这些多出来的可以放最后，多出几个时间加几。因为在最后一组，所以不需要增加暂停时间了

### 代码

```javascript
/**
 * @param {character[]} tasks
 * @param {number} n
 * @return {number}
 */
var leastInterval = function (tasks, n) {
  if (n < 1) return tasks.length
  let map = new Map()
  for (let task of tasks) {
    map.set(task, map.has(task) ? map.get(task) + 1 : 1)
  }

  let counts = [...map].map(item => item[1]).sort((a, b) => b - a)
  let maxCount = 0
  for (let count of counts) {
    if (count === counts[0]) maxCount++
    else break
  }
  let sum = (counts[0] - 1) * (n + 1) + 1
  sum = sum + maxCount - 1
  if (sum < tasks.length) return tasks.length

  return sum
}
```