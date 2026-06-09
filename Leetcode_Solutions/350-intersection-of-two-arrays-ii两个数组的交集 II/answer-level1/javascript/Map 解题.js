### 解题

思路: 使用字典 Map 的数据结构来统计次数。

1. 将 num1、nums2 各自出现的次数分别统计存进 nums1Map 与 nums2Map 中;
2. 根据题目说明中的条件`可以不考虑输出结果的顺序`, 因而可以以 num1、nums2 相同的 key 中较小的值为输出次数, 将其输出;

```js
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  const nums1Map = getMap(nums1)
  const nums2Map = getMap(nums2)

  const result = []

  nums1Map.forEach((nums1Value, key) => {
    const nums2MapHasKey = nums2Map.get(key)
    if (nums2MapHasKey) {
      for (let i = 0; i < Math.min(nums1Value, nums2MapHasKey); i++) {
        result.push(key)
      }
    }
  })

  return result
};

var getMap = function(arr) {
  const map = new Map()
  for (let i = 0; i < arr.length; i++) {
    const getValue = map.get(arr[i])
    if (!getValue) {
      map.set(arr[i], 1)
    } else {
      map.set(arr[i], getValue + 1)
    }
  }
  return map
}
```

### 姊妹题

349

> [javascript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)