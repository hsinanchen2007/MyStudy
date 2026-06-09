## 构建hashMap，遍历求解
```
/**
 * @description
 * 首次将答案设置为首个字母的全部结果
 * 遍历电话号码
 * 将当前的答案和下一个数字对应的
 * 字母组合传入函数
 * 函数将此次答案和新的字母数组结合
 * 返回新的结果
 * 不断执行循环，更新答案ans
 * 最后返回
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  let map = {
    2: ['a', 'b', 'c'],
    3: ['d', 'e', 'f'],
    4: ['g', 'h', 'i'],
    5: ['j', 'k', 'l'],
    6: ['m', 'n', 'o'],
    7: ['p', 'q', 'r', 's'],
    8: ['t', 'u', 'v'],
    9: ['w', 'x', 'y', 'z'],
  };
  let ans = [];
  // 边界处理
  if (map[digits[0]]) {
    ans = map[digits[0]];
  } else {
    return [];
  }
  let i = 1;
  while (digits[i]) {
    // 不断更新当前值
    ans = backtrack(ans, map[digits[i]]);
    i++;
  }
  return ans;
};

/**
 * 
 * @param {Array} combinations 当前组合
 * @param {String} digit 当前号码的下一位对应的英文数组
 */
function backtrack(combinations, digit) {
  let ans = [];
  for (let i = 0; i < combinations.length; i++) {
    for (let j = 0; j < digit.length; j++) {
      ans.push(combinations[i] + digit[j]);
    }
  }
  return ans;
}

```

## 递归求解，还不是很理解
```
/**
 * @description
 * 递归思想  
 * 有点难理解
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  if (!digits) {
    return [];
  }
  var len = digits.length;
  var map = new Map();
  map.set('2', 'abc');
  map.set('3', 'def');
  map.set('4', 'ghi');
  map.set('5', 'jkl');
  map.set('6', 'mno');
  map.set('7', 'pqrs');
  map.set('8', 'tuv');
  map.set('9', 'wxyz');
  var result = [];

  function _generate(i, str) {
    // terminator
    if (i == len) {
      result.push(str);
      return;
    }
    // process
    // drill down
    var tmp = map.get(digits[i]);
    for (var r = 0; r < tmp.length; r++) {
      _generate(i + 1, str + tmp[r]);
    }
  }
  _generate(0, '');
  return result;
};
```