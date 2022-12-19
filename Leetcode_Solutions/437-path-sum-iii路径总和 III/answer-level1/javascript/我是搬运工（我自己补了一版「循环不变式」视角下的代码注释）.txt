惭愧，自己做不出来。在 leetcode.com 上看到一个讲解非常清晰的帖子。搬运一下。

[Python step-by-step walk through. Easy to understand. Two solutions comparison. : ) - LeetCode Discuss](https://leetcode.com/problems/path-sum-iii/discuss/141424/Python-step-by-step-walk-through.-Easy-to-understand.-Two-solutions-comparison.-%3A-))



下面是自己改写为 JS 的代码，带注释。

```js
// 双层递归暴力解题，n^2 复杂度
// 正常的深度递归之外，在每一节点处，设置一个子递归
var pathSum = function(root, sum) {
  let res = 0
  function travel(node) {
    // 到达空节点，直接回退
    if (node == null) return
    // 子递归搜寻满足要求的路径解
    subTravel(node, sum)
    travel(node.left)
    travel(node.right)
  }

  function subTravel(node, target) {
    // // 到达空节点，直接回退
    if (node == null) return
    // 剩余的和如果与当前节点的值相等，则说明搜寻到一个目标解
    if (node.val === target) res += 1
    // 只要节点非空，就继续向下搜寻
    subTravel(node.left, target - node.val)
    subTravel(node.right, target - node.val)
  }

  travel(root)
  return res
}

// 巧用前缀和与缓存实现线性复杂度
var pathSum = function(root, sum) {
  // 预置一个历史前缀和为 0 的缓存，兼容从 root 出发的路径解
  let res = 0, cache = {0: 1}

  function dfs(node, prefixPathSum=0) {
    // 到达空节点，直接回退
    if (node == null) return
    // 更新当前节点的前缀和
    prefixPathSum += node.val
    // 若最新计算出的历史前缀和存在于缓存中，则遇到了一个新的路径解
    let oldPrefixPathSum = prefixPathSum - sum
    if (oldPrefixPathSum in cache) res += cache[oldPrefixPathSum]
    // 将当前前缀和计入缓存
    cache[prefixPathSum] = (cache[prefixPathSum] || 0) + 1
    // 继续向下遍历当前节点的所有子路径
    dfs(node.left, prefixPathSum)
    dfs(node.right, prefixPathSum)
    // 当前节点的所有子路径遍历完毕，回退到父节点之前需要将当前节点的前缀和移出缓存
    cache[prefixPathSum] -= 1
  }

  dfs(root)
  return res
};
```


补一版「循环不变式」视角下的代码，逻辑几乎没变，但注释逻辑统一
```js
var pathSum = function(root, sum) {
  // initialize count to save result
  let count = 0
  // initialize loop invariant related variable: prefixSumMap for current node
  // with root node, we have {0: 1}
  let prefixSumMap = {0: 1}

  // initialize loop invariant related variable: prefixSum
  function loop(node = root, prefixSum = 0) {
    // check if we should return
    if (node == null) return

    // update prefixSum for current node
    prefixSum += node.val
    
    // update count
    count += (prefixSumMap[prefixSum - sum] || 0)
    // update loop invariant related variable prefixSumMap for node.left and node.right
    prefixSumMap[prefixSum] = (prefixSumMap[prefixSum] || 0) + 1

    // continue loop
    loop(node.left, prefixSum)
    loop(node.right, prefixSum)

    // when we finish to loop node.left and node.right
    // update loop invariant related variable prefixSumMap
    // because the prefixSum of current node is no longer needed
    prefixSumMap[prefixSum] -= 1
  }

  loop()

  // termination: count is the answer
  // and prefixSumMap (where value is not zero) should be {0: 1} again
  for (let [k, v] of Object.entries(prefixSumMap)) {
    if (v) console.assert(k == 0 && v == 1)
  }

  return count
}
```
