## 思路:

将输入的数字拆分, 关联对应的字母, 利用数组的循环逐次拼接, 最终生成完整的数组.
![](https://pic.leetcode-cn.com/50eb7e8eb7b293f70f5c8dab515710a02e5fb0bfc6985dd4de75a19167de291f-file_1583552558917)

## 具体步骤:
1. 定义数组 `map` 存放数字对应的字母
2. 接收传入字符串, 利用 `split()` 函数拆分
3. 利用 `forEach()` 函数将字符串数组与 `map` 数组关联如: `["2", "3", "4"] => ["abc", "def", 'ghi', 'jkl']` 
4. 使用上一步生的数组, 每次利用这个数组的第0位与第1位进行组合, 组合生成的结果 `splice()` 返回数组, 放在第0位上, 再与后面一位进行组合, 直到该数组的长度为 1 时, 返回第 0 位即可.
5. 对输入 "" 或 个位数(如"1", "2", "3"), 进行兼容.
6. 提交代码

## 完整代码
```js
/**
 * @param {string} digits 输入的字符串
 * @return {string[]}
 */
var letterCombinations = function(digits) {
  // 定义数组 `map` 存放数字对应的字母
  let map = ['', 1, 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
  // 兼容输入的是 ""
  if(digits === '') {
    return []
  }
  // 将输入的号码进行分隔, 234 => [2,3,4]
  let num = digits.split('')
  // 保存输入号码对应的字母, ["2", "3", "4"] => ["abc", "def", 'ghi', 'jkl']
  let code = []
  num.forEach(item => {
    if(map[item]) {
      code.push(map[item])
    }
  });
  // 兼容输入的是个位数(如"1", "2", "3")
  if(code.length === 1) {
    var temp = []
    for(let i = 0; i < code[0].length; i ++) {
      temp.push(code[0][i])
    }
    return temp
  }
  let comb = arr => {
    var temp = []
    for(let i = 0; i < arr[0].length; i ++) {
      for(let k = 0; k < arr[1].length; k ++) {
        temp.push(`${arr[0][i]}${arr[1][k]}`) // 这里使用了模板字符串
      }
    }
    arr.splice(0, 2, temp)
    if(arr.length > 1) {
      comb(arr)
    }
    return arr[0]
  }
  return comb(code)
};
```

## 提交结果

![](https://pic.leetcode-cn.com/0f04efbf5d61b769e8814d49863692e9dea5be73b3db44e73fbd67d9cd28d3bc-file_1583552558911)