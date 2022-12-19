对于这道供暖题的解法，有二分查找和滑动查找两种思路。时间复杂度如下(m 为房屋数量，n 为供暖器数量)：
1. 二分查找只需对供暖器排序： O(mlog(n)) + O(nlog(n)))
2. 滑动查找需要对供暖器和房屋排序：O(mlog(m)) + O(nlog(n))

如果不考虑 m 和 n 的关系，复杂度可以说是一样的，但二分查找依然稍稍有优势，但数量级没有差别。

不过，考虑现实情况时，房屋数量很可能远远大过供暖器数量，故而二分查找复杂度有可能归约为 O(mlog(n))，所以优过滑动查找。

```
var findRadius = function(houses, heaters) {
  heaters.sort((a, b) => a - b)
  heaters.unshift(-Infinity)
  heaters.push(Infinity)
  let radius = 0
  for (let e of houses) {
    let [lo, hi] = [0, heaters.length]
    while(lo < hi) {
      let mid = (lo + hi) / 2 | 0
      if (heaters[mid] > e) hi = mid
      else lo = mid + 1
    }
    let distance = Math.min(e - heaters[lo - 1], heaters[lo] - e)
    radius = Math.max(radius, distance)
  }
  return radius
};
```
