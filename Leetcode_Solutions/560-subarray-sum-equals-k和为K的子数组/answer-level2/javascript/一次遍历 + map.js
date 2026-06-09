### 解题思路

大家好，我是 17

官方发布的方法中，速度最优的是一次遍历 + map。

想法和两数和很象。都是向前走，回头看。先看最后一个元素，会好理解一些。
比如加到最后一个元素的和是 100，那么和为10 的位置在哪里呢？向前找去，一定是和为 90 的位置，因为从90 到 100 之间的和为 10。

每个元素都这样向前看，就得到了总数。

`map.set(0, 1)` 是因为当和正好为 k 的时候，需要一个和为 0 的位置，方便统一处理。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
  let map = new Map()
  let count = 0
  let sum = 0
  map.set(0, 1)
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i]
    let otherSum = sum - k
    if (map.has(otherSum)) {
      count += map.get(otherSum)
    }
    map.has(sum) ? map.set(sum, map.get(sum) + 1) : map.set(sum, 1)
  }
  return count
};
```

另外还有一个解法 ，虽然时间长，但是空间复杂度为常数，也是需要了解的

`/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
  let count = 0
  let sum=0
  for (let i = 0; i < nums.length; i++) { 
    sum=0
    for (let j = i; j < nums.length; j++){
      sum += nums[j]
      if(sum===k) count++
    }
  }
  return count
};`