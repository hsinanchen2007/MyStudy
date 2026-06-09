### 解题思路

大家好，我是 17

根据题意，要求空间复杂度 O(1) ,时间复杂度 O(n),只能用摩尔投票法了。
解题的关键是需要理解摩尔投票法。

我用白话解释一下。首先看下求超半数的原理

超半数的数最多只可能有一个

1. 把一个众数和其它分成两堆
2. 每次拿走不同的两个数
3. 剩下的可能是众数
4. 扫描所有数据验证

第三步再解释一下。每次拿走不同的两个数有两种情况
第一种是每次拿一个众数和一个其它数，这种结果剩下的是众数
每二种是每次拿两个其它数，剩下的也是众数
所以如果众数存在，那么剩下的一定是众数。

回头看第二种情况，每次拿的可能不包含众数，这就导致非众数可能会剩下来。所以最后一步，需要扫描所有数据进行验证。

本题是求超 1/3,超 1/3 的  最多只能有两个

1. 把两个众数和其它分成三堆
2. 每次拿走不同的三个数
3. 剩下的可能是众数
4. 扫描所有数据验证


代码里的 `count1 === 0 && n !== card2` 和 `count2 === 0 && n !== card1` 是特意这么写的，是为了让大家好理解。强调 “拿走的是不同的三个数” 。如果追求代码简洁，可以调整下判断顺序，把 `n !== card2`  `n !== card1` 省略。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function (nums) {
  let card1, card2
  let count1 = 0, count2 = 0
  for (let n of nums) {
    if (count1 === 0 && n !== card2) {
      card1 = n
      count1++
    }
    else if (count2 === 0 && n !== card1) {
      card2 = n
      count2++
    }
    else if (card1 === n) {
      count1++
    }
    else if (card2 === n) {
      count2++
    }
    else {
      count1--
      count2--
    }
  }
  count1 = 0
  count2 = 0
  for (let n of nums) {
    if (n === card1) count1++
    if (n === card2) count2++
  }
  let result = []
  if (count1 > Math.floor(nums.length / 3)) {
    result.push(card1)
  }
  if (count2 > Math.floor(nums.length / 3)) {
    result.push(card2)
  }
  return result
};
```