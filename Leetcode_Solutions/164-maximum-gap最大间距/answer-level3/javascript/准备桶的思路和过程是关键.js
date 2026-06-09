我是参考各路题解，综合了一个最适合自己的写法。变量名尽量表意。

```
// 桶排序与鸽笼原理
var maximumGap = function(nums) {
  // 个数不足 2 时，直接返回 0
  if (nums.length < 2) return 0
  let min = Infinity, max = -Infinity
  for (let e of nums) {
    if (e > max) max = e 
    if (e < min) min = e
  }
  // 间距的个数是数组长度减一
  let intervalNums = nums.length - 1
  // 有了间距个数和最大最小值，可以求得间距可能的最小值
  let minGap = (max - min) / intervalNums | 0
  // 进而得到桶的容量，其实就是兼容 minGap 为 0 的情况
  let bucketCapacity = minGap || 1
  // 然后得到桶的数量，使桶刚刚能盛下所有数组元素
  let bucketSize = ((max - min) / bucketCapacity | 0) + 1
  
  // 因为我们是利用可能的最小间距来准备的桶的容量和个数
  // 在这种桶的布局下，最大间距如果变大，则最大间距必然出现在装有元素的相邻桶与桶之间（为什么必然，参考鸽笼原理）
  // 所以每个桶只记录最大最小值和是否有元素入桶
  let buckets = Array(bucketSize)
  for (let i = 0; i < bucketSize; i++) {
    buckets[i] = {min: Infinity, max: -Infinity, used: false}
  }

  // 将元素入桶
  for (let e of nums) {
    let i = ((e - min) / bucketCapacity) | 0
    buckets[i].used = true
    buckets[i].min = Math.min(e, buckets[i].min)
    buckets[i].max = Math.max(e, buckets[i].max)
  }
  // 最大间距最小为 minGap
  // 桶的最大值总比全局最小 min 大
  let maxGap = minGap, preMax = min
  for (let b of buckets) {
    if (b.used) {
      // 将有元素的相邻桶与桶之间的间距更新到最大间距上
      maxGap = Math.max(maxGap, b.min - preMax)
      preMax = b.max
    }
  }
  return maxGap
};
```
