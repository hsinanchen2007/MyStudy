### 解题思路
1 首先给数组的length-1型加1，结果为10 接着调用addOne(digits, 1, --index)，结果！==10 返回digits，
2  （index === -1 && addNum != 0）需要 digits.unshift(1);并 return digits;

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
const plusOne = function(digits) {
  return addOne(digits, 1,  digits.length - 1);
};
function addOne(digits, addNum, index) {
  if (index === -1 && addNum != 0) {
    digits.unshift(1);
    return digits;
  }
  if (digits[index] + addNum === 10) {
    digits[index] = 0;
    return addOne(digits, 1, --index);
  }
  digits[index] = digits[index] + addNum;
  return digits;
}
```