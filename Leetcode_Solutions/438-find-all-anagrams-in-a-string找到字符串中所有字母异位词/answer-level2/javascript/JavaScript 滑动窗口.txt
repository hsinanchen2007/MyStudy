花了半天, 用类似滑动窗口的思想地解决了该题。思路如下:

1. 首先将 p 字符串中各字母出现的频率统计在 `targetObj`;
2. 针对 s 字符创声明双指针 left、right
   1. 如若当前 right 的位置在 targetObj `有对应字段且其不大于` targetObj 对应字段的值, 则向右偏移 right 指针的位置;
   2. 如若当前 right 指针的位置在 targetObj `无对应字段`, 则将 left 的位置移到 right 字段的位置;
   3. 如若当前 right 指针的位置在 targetObj `有对应字段且大于` targetObj 对应字段的值, 则向右偏移 left 指针的位置;

> 需要考虑的点, `字符串是否会重复`。比如 s 为 'baa', p 为 'aa'。

```js
/**
 * @param {string} s
 * @param {string} p
 * @return {number[]}
 */
var findAnagrams = function(s, p) {
  const pLength = p.length
  const initHashObj = {} // 初始化 hash 对象
  let hashObj = {}
  const targetObj = {}
  for (let i = 0; i < p.length; i++) {
    targetObj[p[i]] = typeof(targetObj[p[i]]) === 'number' ? targetObj[p[i]] + 1 : 0
    initHashObj[p[i]] = 0
    hashObj[p[i]] = 0
  }

  const result = [] // 存储结果

  let left = 0, right = 0

  while (left < s.length && right < s.length) {
    if (typeof(hashObj[s[right]]) === 'number' && hashObj[s[right]] <= targetObj[s[right]]) {
      hashObj[s[right]] = hashObj[s[right]] + 1
      if (right - left + 1 === pLength) result.push(left)
      right++
    } else if (typeof(hashObj[s[right]]) !== 'number') {
      right++
      left = right
      hashObj = JSON.parse(JSON.stringify(initHashObj))
    } else {
      hashObj[s[left]] !== initHashObj[s[left]] && (hashObj[s[left]] = hashObj[s[left]] - 1)
      left++
    }
  }

  return result
};
```

### 相似题目

76

> [JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)