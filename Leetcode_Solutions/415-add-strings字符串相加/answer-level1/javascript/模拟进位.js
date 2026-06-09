```javascript
/**
 * 类似题目 67. 二进制求和（https://leetcode-cn.com/problems/add-binary/）
 * @param {string} num1
 * @param {string} num2
 * @returns {string}
 */
const addStrings = (num1, num2) => {
  let arr = []
  let carry = 0
  let len = num1.length > num2.length ? num1.length : num2.length
  while (num1.length < len) { num1 = '0' + num1 } // 0 对齐
  while (num2.length < len) { num2 = '0' + num2 }
  for (let i = len - 1; i >= 0; i--) {
    let sum = Number(num1[i]) + Number(num2[i]) + carry
    if (sum >= 10) {
      arr.push(sum % 10)
      carry = 1
    } else {
      carry = 0
      arr.push(sum)
    }
  }
  return carry === 0 ? arr.reverse().join('') : carry + arr.reverse().join('')
}
```