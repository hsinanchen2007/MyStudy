# 875. 爱吃香蕉的珂珂

**Medium**

珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。

珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  

珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。

返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。

 

示例 1：
```!
输入: piles = [3,6,7,11], H = 8
输出: 4
```
示例 2：
```!
输入: piles = [30,11,23,4,20], H = 5
输出: 30
```
示例 3：
```!
输入: piles = [30,11,23,4,20], H = 6
输出: 23
```

提示：

1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9

## 解题

采用二分搜索。套用模板，区别只是判断条件有所不同。


1. 根据题意，得知`left`为最小值1， `right`为`max(piles[i])`。当然，也可以设置`right = 1e9`
1. 当`left < right`时，进行经典二分查找，`mid`满足判断条件，则区间为`[left, mid]`，否则，区间为`[mid+1, right]`。
1. 如果`mid+1 >= right`，则会跳出`while`循环。因此我们可以得到最小值为`left`。


1. 以上为**二分查找套路**，在这题中的**判断条件**为用mid的速度，能否在H时间内吃完。
1. 在canDo函数中，我们循环piles。H减去吃那堆香蕉的所花时间ceil(p/K)。
1. 判断H是否大于0，即为能否在H时间内吃完

- 复杂度分析
  - 时间复杂度：O(NlogW)，其中 N = piles.length，W = max(piles[i])
  - 空间复杂度：O(1)

```js
/**
 * @param {number[]} piles
 * @param {number} H
 * @return {number}
 */
var minEatingSpeed = function(piles, H) {
  let left = 1, right = Math.max(...piles)
  while(left < right) {
      let mid = (left + right) >> 1
      canDo(piles, H, mid) ? (right = mid) : (left = mid + 1)
  }
  return left
  
  function canDo(piles, H, K) {
      for (let p of piles) {
          H -= Math.ceil(p / K)
          if (H < 0) return false
      }
      return true
  }
};
```