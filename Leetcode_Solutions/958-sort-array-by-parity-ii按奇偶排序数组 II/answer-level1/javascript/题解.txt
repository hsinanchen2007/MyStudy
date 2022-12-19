### 解题思路
解法一：新开一个数组，遍历原数组，偶数放偶数位，奇数放奇数位
解法二：不开新数组，找到为偶数的奇数位，和为奇数的偶数位，交换

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
  let r = []
  let odd = 1
  let even = 0
  A.forEach(item => {
    if (item % 2 === 1) {
      r[odd] = item
      odd += 2
    } else {
      r[even] = item
      even += 2
    }
  })
  return r
};
```

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
  let odd = 1
  let even = 0
  const len = A.length
  // 只要有一个遍历完就可以了
  while (odd < len && even <len) {
    // 找到奇指针对应的数不为奇数的地方
    while (odd < len && A[odd] % 2 === 0) {
      odd += 2
    }
    // 找到偶数针对应的数不为偶数的地方
    while (even < len && A[even] % 2 === 1) {
      even += 2
    }
    // 交换
    if (odd < len && even < len) {
      [A[odd], A[event]] = [A[event], A[odd]]
    }
  }
};
```