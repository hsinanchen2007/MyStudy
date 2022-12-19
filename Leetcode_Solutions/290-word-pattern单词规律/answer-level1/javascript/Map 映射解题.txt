思路:

使用 patternMap 与 strArrMap 分别存储 `pattern => strArrMap` 与 `strArrMap => pattern` 的映射, 当存在一对多映射的情况时, 则它们非完全匹配, 否则是完全匹配的。

```js
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
  const strArr = str.split(' ')
  if (pattern.length !== strArr.length) return false

  const patternMap = new Map()
  const strArrMap = new Map()

  for (let i = 0; i < pattern.length; i++) {
    const getPatternMap = patternMap.get(pattern[i])
    const getStrArrMap = strArrMap.get(strArr[i])
    if (!getPatternMap) {
      patternMap.set(pattern[i], strArr[i])
    } else if (getPatternMap !== strArr[i]) {
      return false
    }

    if (!getStrArrMap) {
      strArrMap.set(strArr[i], pattern[i])
    } else if (getStrArrMap !== pattern[i]) {
      return false
    }
  }

  return true
};
```

### 相关题目

202、205、242、349、350、451

> [JS 题解](https://github.com/MuYunyun/blog/blob/master/BasicSkill/LeetCode/README.md)