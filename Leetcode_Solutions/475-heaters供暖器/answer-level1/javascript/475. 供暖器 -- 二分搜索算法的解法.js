  这道题的难点在于是否读懂了题目：找到一个最小半径使得加热器覆盖所有房子。

  那么最简单的解法就是遍历所有的房子的同时，遍历加热器找出距离该房子的最小距离，那么所有房子中的最大距离即为加热器覆盖的最小半径，那么整个过程的时间复杂度就是 O(n*m)，对于加热器的搜索可以采用二分搜索算法优化，那么时间复杂度可以优化为 O(nlog m):


```JavaScript
/**
 * 
 * 475. Heaters
 * 
 * Easy
 * 
 * 184ms 100%
 * 39mb 74.45%
 */
const findRadius = (houses, heaters) => {
  let ans = Number.MIN_SAFE_INTEGER
  // 排序
  heaters.sort((a, b) => a - b)
  const len = heaters.length

  for (let i = 0, max = houses.length; i < max; i++) {
    const house = houses[i]
    const targetPos = binarySearch(heaters, 0, len - 1, house)
    let closestDistance = Number.MAX_SAFE_INTEGER
    if (heaters[targetPos] === house) {
      ans = Math.max(ans, 0)
      continue
    }
    // 比较前一个 和 后一个 得到最小值
    const pre = heaters[targetPos - 1]
    const cur = heaters[targetPos]
    if (pre !== undefined) {
      closestDistance = Math.min(closestDistance, Math.abs(house - pre))
    }
    closestDistance = Math.min(closestDistance, Math.abs(house - cur))

    ans = Math.max(ans, closestDistance)
  }

  return ans
}

function binarySearch(array, start, end, target) {
  while (start < end) {
    const mid = Math.floor(start + (end - start) / 2)
    const middle = array[mid]
    if (target > middle) {
      start = mid + 1
    } else {
      end = mid
    }
  }
  return start
}
```

  希望上述解题思路能够帮助到您，更多解题思路详见[前端工程师的 LeetCode 之旅](https://github.com/15751165579/LeetCode)
