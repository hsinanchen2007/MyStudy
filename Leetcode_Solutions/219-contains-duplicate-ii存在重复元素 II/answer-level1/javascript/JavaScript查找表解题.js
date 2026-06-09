### 解法

* 遍历当前 nums, 维护一个队列 arr 来存储 k 个数值, 判断该队列 arr 中是否包含当前遍历值 nums[l];
  * 若有, 则返回 true;
* 若遍历结束, 则返回 false;

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  const arr = []

  let l = 0
  let r = nums.length

  while (l < r) {
    if (arr.indexOf(nums[l]) > -1) {
      return true
    }
    if (arr.length < k) {
      arr.push(nums[l])
    } else if (arr.length >= k && k > 0) {
      arr.shift(arr[0])
      arr.push(nums[l])
    }
    l++
  }

  return false
}
```

![](https://pic.leetcode-cn.com/2267c41f908da4502fd81607cda13df5ae18f133835ba1b348893da698bd828c.jpg-400)

算法时间复杂度是 NlogN 级别的, 执行时间花了 1800ms。

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
  const temSet = new Set()

  let l = 0
  let r = nums.length

  while (l < r) {
    if (temSet.has(nums[l])) {
      return true
    }
    if (temSet.size < k) {
      temSet.add(nums[l])
    } else if (temSet.size >= k && k > 0) {
      temSet.delete(nums[l - k])
      temSet.add(nums[l])
    }
    l++
  }

  return false
}
```

![](https://pic.leetcode-cn.com/6265562224a82d669e0ec7f12151fc728cb0c8d69ad1c46672cb555d9f9e287f.jpg-400)

使用 Set 用同样的思路实验, 时间复杂度为 O(N), 其执行时间比之前用数组队列的实现快了很多。

> 为确保内容的实时性, 可以关注 [JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)