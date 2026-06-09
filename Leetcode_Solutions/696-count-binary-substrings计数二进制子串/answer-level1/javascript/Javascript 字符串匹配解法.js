### 解题思路
使用字符串匹配来找到子串中符合条件的值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countBinarySubstrings = function(s) {
  let result = 0;

  // 字符串匹配算法
  const match = (subString) => {
    // 先找到开头的连续数字[0|1]
    let startStr = subString.match(/^((0+)|(1+))/)[0]
    subString = subString.slice(0, startStr.length * 2)
    // 推算出组合字符串
    let endStr = (startStr[0] ^ 1).toString().repeat(startStr.length)
    // 查看字符串中是否匹配组合字符串
    return subString.startsWith(`${startStr}${endStr}`)
  }

  // 循环计算每个子串中出现符合条件的字符情况，如果找到就+1，并break到下一个子串
  for (let index = 0; index < s.length-1; index++) {
    let subString = s.slice(index)
    if (match(subString)) {
      result += 1;
    }
  }

  return result
};
```