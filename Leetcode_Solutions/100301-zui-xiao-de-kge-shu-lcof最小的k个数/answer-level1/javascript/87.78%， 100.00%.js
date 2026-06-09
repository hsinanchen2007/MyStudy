### 解题思路
先遍历 arr 把元素 n 为 key，出现的次数作为 val 存到对象中。

对象中的 key 为数值的时候用 in 遍历，得到的 key（index） 是有序的。

既然有了**有序的列表**和**每个数字出现的次数**，那么就将对象中的 key 填入结果列表 r 就行了，k 只是用来判断一次应该填入几个 n 的。

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
  const obj = {}
  const r = []
  for (let n of arr) {
    obj[n] ? (obj[n]++) : (obj[n] = 1)
  }
  for (let index in obj) {
    const val = obj[index]
    if (r.length + val <= k) {
      r.push(...Array(val).fill(index))
    } else {
      const left = k - r.length
      r.push(...Array(left).fill(index))
    }
  }
  return r
};
```