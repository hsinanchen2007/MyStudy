### 解题思路

我们要求的是**最多** K 个工程师的团队表现值

团队的表现值 = 至多 K 个工程师的速度和 * 至多 K 个工程师中的最小效率值

假定选中的至多 K 个工程师中的效率最小值为 x ，那么所有其他工程师的效率值一定是大于 x。

所以我们的核心思路是：先以效率对所有工程师做降序排序，每次选定一个效率值作为 x，从效率值大于 x 的工程师（即左侧的工程师）中找到速度最大的至多 K 个工程师，从而计算他们的团队表现值。
为了方便的找到效率大于 x 的速度最大的 K 个工程师，使用一个容量为 K 的最小堆来维护。

**需要注意的是**：

1. 在 JS 中，没有现成的最小堆或优先队列的实现，需要自己实现一个最小堆。
2. 在 JS 中，Number 的最大值是 Number.MAX_SAFE_INTEGER 9007199254740991，在某些 case 中会发生大于这个值得情况，使得最终的结果出现偏差。因此答案中需要增加 **BigInt** 的支持。

### 代码

```javascript
var maxPerformance = function(n, speed, efficiency, k) {
  let arr = []
  for (let i = 0; i < n; i++) {
    arr.push([speed[i], efficiency[i]])
  }
  arr.sort((a, b) => b[1] - a[1])
  let minHeap = new MinHeap()
  let speedSum = 0
  let minEfficiency
  let res = 0
  for (let i = 0; i < n; i++) {
    minEfficiency = arr[i][1]
    speedSum = BigInt(speedSum) + BigInt(arr[i][0])
    minHeap.insert(BigInt(arr[i][0]))
    if (minHeap.size() > k) speedSum -= minHeap.delete()
    let tmp = BigInt(minEfficiency) * BigInt(speedSum)
    res = tmp > res ? tmp : res
  }

  return res % 1000000007n
}

function MinHeap() {
  this.heap = [-Infinity]
}
MinHeap.prototype.insert = function(x) {
  this.heap.length++
  let child = this.heap.length - 1
  let parent = parseInt(child / 2)
  while (this.heap[parent] > x) {
    this.heap[child] = this.heap[parent]
    child = parent
    parent = parseInt(child / 2)
  }
  this.heap[child] = x
}
MinHeap.prototype.delete = function() {
  let size = this.size()
  if (size <= 0) return
  let res = this.heap[1]
  let item = this.heap[size]
  this.heap.length--
  size--
  let parent, child
  for (parent = 1; parent * 2 <= size; parent = child) {
    child = parent * 2
    if (child + 1 <= size && this.heap[child + 1] < this.heap[child])
      child = child + 1
    if (item < this.heap[child]) break
    this.heap[parent] = this.heap[child]
  }
  this.heap[parent] = item
  return res
}
MinHeap.prototype.size = function() {
  return this.heap.length - 1
}
```