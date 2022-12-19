### 题解

题解 1: 暴力法

```js
var twoSum = function(nums, target) {
  var length = nums.length
  for (var x = 0; x < length; x++) {
    for (var y = x + 1; y < length; y++) {
      if (nums[x] + nums[y] === target) {
        var arr = []
        arr.push(x)
        arr.push(y)
        return arr
      }
    }
  }
}
```

* 时间复杂度: O(n^2)
* 空间复杂度: O(1)

题解 2-1: 哈希表

思路:

> 需要留意的是, 如果数组中有重复的值比如 [5, 5], target = 10 这种情况的处理

* 遍历一次数组, 查询当前`哈希表`中是否有和当前索引值 `nums[i]` 对应的匹配值 `target - nums[i]`;
  * 若有, 则返回它们两个值的索引;
  * 若没有, 则将当前索引值和下标存入哈希表中;

```js
var twoSum = function(nums, target) {
  let numsObj = {}
  for (let i = 0; i < nums.length; i++) {
    let current = nums[i]
    let match = target - current
    if (match in numsObj) {
      return [i, numsObj[match]]
    }
    numsObj[current] = i
  }
}
```

* 时间复杂度: O(n)
* 空间复杂度: O(n)

题解 2-2: 使用 Map, 思路同哈希表

```js
var twoSum = function(nums, target) {
  var map = new Map()

  for (let i = 0; i < nums.length; i++) {
    const targetValue = target - nums[i]
    const getTargetValue = map.get(targetValue)
    if (typeof(getTargetValue) === 'number') {
      return [i, getTargetValue]
    }
    map.set(nums[i], i)
  }
}
```

* 时间复杂度: O(n)
* 空间复杂度: O(n)

### 相似题目

15、16、18

> [JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)