翻了下评论，发现什么人用递归，我给补充下吧。关键我只想到了用递归，其它的暂时没想好。
```
/**
 * 部分递归，如果当前位小于9则直接加1，否则递归调用直到到达首位递归结束
 * 最坏时间复杂度O(n) ?
 * 最坏空间复杂度O() ?
 */
var recursivePlus = function(digits, i) {
  if (digits[i] < 9) {
    digits[i] += 1
  } else {
    digits[i] = 0
    if (i === 0) {
      digits.unshift(1)
      return
    }
    recursivePlus(digits, i - 1)
  }
}

/**
 * 部分递归
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
  const n = digits.length

  if (n === 0) {
    return []
  }
  recursivePlus(digits, n - 1)
  return digits
};
```