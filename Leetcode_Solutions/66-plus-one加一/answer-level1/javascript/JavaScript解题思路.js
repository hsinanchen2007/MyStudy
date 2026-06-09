### 解题思路
从数组末尾遍历数组，不等于9就直接加一并返回结果。等于9就把那一位置0，进入第二次循环，判断倒数第二个数是否等于9...  最后声明一个新数组第一位是1，之后的数就是digits的值

### 代码

```javascript
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
 let arr = []
  for (let i = digits.length - 1; i >= 0; i--) { 
    if (digits[i] !== 9) { // 最后一位不等于9就直接加一
      digits[i]++
      return digits
    }
    digits[i] = 0 // 将等于9的那一位置0
  }
  arr[0] = 1
  digits.forEach(ele => {
      arr.push(ele)
  })
  return arr;
};
```