### Analyze

思路:

首先弄清题意, 输入的数组 points 中能产生中多少种 [i, j, k] 的数组, 使 i 到 j 的距离与 i 到 k 的距离相等。

因此可以将 i 的位置固定, 使用`查找表`将到 i 的距离作为 key, 将该距离出现的次数作为 value, 若该次数大于 1 则说明能构成回旋镖。(比如出现 4 次, 在剩下的 j, k 两个位置中能构成 4 * 3 个回旋镖)

![](https://pic.leetcode-cn.com/6729fb28446e4d74b4d359c746e5a07ee334bcf62efb83667ae49268f80790b7.jpg-400)

```js
/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfBoomerangs = function (points) {
  // avoid losing the precision
  const getDistancePow = (x, y) => {
    return Math.pow((y[0] - x[0]), 2) + Math.pow((y[1] - x[1]), 2)
  }

  let result = 0

  for (let p = 0; p < points.length; p++) {
    const tmpMap = new Map()
    for (let n = 0; n < points.length; n++) {
      if (p === n) continue
      const distancePow = getDistancePow(points[p], points[n])
      const hasDistancePow = tmpMap.has(`${distancePow}`)
      if (hasDistancePow) {
        tmpMap.set(`${distancePow}`, tmpMap.get(`${distancePow}`) + 1)
      } else {
        tmpMap.set(`${distancePow}`, 1)
      }
    }
    tmpMap.forEach((value, key) => {
      if (value > 1) {
        const sum = value * (value - 1)
        result += sum
      }
    })
  }

  return result
}
```

![](https://pic.leetcode-cn.com/65570dddadaa81fa851f10687bf0c38a2225df998cb18965adb4584d09fdd411.jpg)

### Similar Title

149

> 为确保内容的实时、准确性, 可以[查看原文](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)