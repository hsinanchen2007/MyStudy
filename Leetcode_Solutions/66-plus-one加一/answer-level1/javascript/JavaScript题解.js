从最后一位开始遍历，如果小于9则直接加一并返回该数组；如果等于9则将该位改为0，继续遍历。
如果遍历完成，则直接在首位加1
```
var plusOne = function(digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    if (digits[i] < 9) {
      digits[i]++
      return digits
    }
    digits[i] = 0
  }

  digits.unshift(1)

  return digits
};
```
