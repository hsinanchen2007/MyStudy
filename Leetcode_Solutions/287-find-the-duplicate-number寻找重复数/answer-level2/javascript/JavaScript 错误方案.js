利用 hash 的方案

时间复杂度: O(n)
空间复杂度: O(1) 或者 O(n)，明显不满足约束 -_-

```js
const findDuplicate = nums => {
  const hash = {}

  for (const n of nums) {
    if (hash[n]) {
      return n
    } else {
      hash[n] = true
    }
  }

  return null
}
```
