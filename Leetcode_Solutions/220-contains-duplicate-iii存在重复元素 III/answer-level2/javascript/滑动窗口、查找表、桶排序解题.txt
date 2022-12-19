### Analyze

思路: 参照官方题解该题可以使用桶排序的思想来设置查找表的 key - value。比较好理解的一个例子: 小敏生日在 3 月份, 她想知道是否有其他同学生日和她在 30 天以内, 假设每个月有 30 天, 那么只要找 2 月份和 4 月份两个月生日的同学就行了, 转化到该题目即 key 只要保留一个 value 就行。

> 桶排序的思想: 将数据根据归类划分到若干个区域, 然后对该些区域分别进行排序;

此题综合了滑动窗口、查找表、桶排序的知识, 需要二刷。

```js
| i - j | ≤ k
| nums[i] - nums[j] | ≤ t
```

* 此外需要考虑边界值
  * k <= 0、 t <= 0

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
  if (k < 0 || t < 0) return false
  const getKey = (value) => {
    return Math.floor(value / (t + 1))
  }

  const map = new Map()

  let l = 0
  while (l < nums.length) {
    const key = getKey(nums[l])

    if (map.has(key)) {
      return true
    } else if (map.has(key + 1) || map.has(key - 1)) {
      if (map.get(key + 1) - nums[l] <= t) { return true }
      if (nums[l] - map.get(key - 1) <= t) { return true }
    }

    map.set(key, nums[l])

    if (l >= k) {
      map.delete(getKey(nums[l - k]))
    }

    l++
  }

  return false
}
```

> 为确保内容的实时、准确性, 可以阅读[JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)