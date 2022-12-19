按照老师的思路做的，有些吃内存
```
/**
 * @param {string} str
 * @return {string[]}
 */
var letterCombinations = function(str) {
// 建立电话号码键盘映射
  const maps = ['_', '!@#', 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
  let code = []
  if (!str.length) return code

  // '234' => [2,3,4] => ['abc', 'def', 'ghi']
  str.split('').forEach(value => {
    code.push(maps[value])
  })
  let comb = (arr) => {
    if (arr.length <= 1) {
      return arr.join('').split('')
    }
    // 临时变量保存前两个组合的结果
    let tmb = []
    // 最外层 => arr 的第一个元素，里层 => arr 的第二个元素
    for (let i = 0, l = arr[0].length; i < l; i++) {
      for (let j = 0, m = arr[1].length; j < m; j++) {
        tmb.push(`${arr[0][i]}${arr[1][j]}`)
      }
    }
    // 关键：将组合后的数组，替换掉组合前的原始数组
    code.splice(0, 2, tmb)
    if (arr.length > 1) {
      // 递归
      comb(code)
    } else {
      return tmb
    }
    return arr[0]
  }
  return comb(code)
};
```
