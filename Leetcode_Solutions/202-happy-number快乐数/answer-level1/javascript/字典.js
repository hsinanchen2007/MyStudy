### 题解

* 使用`字典 Map` 来记录循环过程中各个位置上的数字的平方和
  * 若平方和的值为 1, 则跳出循环, 这个数是快乐数;
  * 若平方和的值不为 1, 则判断字典 Map 中是否已有该值;
    * 若字典 Map 中已有该值, 则这个数不是快乐数;

```js
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
  const mapResult = new Map()

  let currentSum = getSum(n)
  while (currentSum !== 1) {
    const getMapResult = mapResult.get(currentSum)
    if (!getMapResult) {
      mapResult.set(currentSum, 1)
    } else {
      return false
    }
    currentSum = getSum(currentSum)
  }
  return true
}

/* 获取数字各个位数之和 */
var getSum = function(num) {
  let sum = 0
  const numStr = String(num)
  for (let i = 0; i < numStr.length; i++) {
    sum = sum + Math.pow(numStr[i], 2)
  }
  return sum
}
```

### 相关题目

205、242、290、349、350、451

> [JavaScript 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)