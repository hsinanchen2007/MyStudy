本来想用动态规划写，发现这样容易理解，不知道算不算回溯
用时90+ 内存60+

```
var letterCombinations = function(digits) {
  // 特殊处理空字符串输入
  if (digits === '') { return [] }
  // 号码盘字典 数组下标对应号码
  let dict = [[],[],['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l'],['m','n','o'],['p','q','r','s'],['t','u','v'],['w','x','y','z']]
  // 初始化结果
  let result = dict[digits[0]]
  // 求两个数组的笛卡尔积组合
  let helper = function (arr1, arr2) {
    let result = []
    for (let i=0; i<arr1.length; i++) {
      for (let j=0; j<arr2.length; j++) {
        result.push(arr1[i] + arr2[j])
      }
    }
    return result
  }
  // 因为用第一个数字初始化 从第二个数字循环到最后
  for (let i=1; i<digits.length; i++) {
    result = helper(result, dict[digits[i]])
  }
  
  return result
};
```
