### 解题思路
此处撰写解题思路

### 代码

```javascript
var compressString = function(S) {
  // 初始化一个最终的字符串结果
  let endString = ''
// 截取最后数字的正则
  let endNumberReg = /[0-9]*$/
// 截取最后数字和前一个字母的正则
  let endWordReg = /[a-zA-Z][0-9]*$/
  for(let i = 0; i < S.length; i++) {
    // 因为题目说最多50000个字符串，所以匹配最后一个字母加数字的时候，把之前的字符串全部干掉
    let matchWord = endString.substring(endString.length - 5, endString.length).match(endWordReg)
    // 如果相等就加1，不相等则等于1
    if (matchWord && matchWord[0][0] == S[i]) {
      let index = (matchWord[0].substring(1, matchWord[0].length)) ^ 0
      endString = endString.replace(endNumberReg, ++index)
    } else {
      endString += S[i] + '1'
    }
  // 题目说如果最终的字符串长度大于或者等于 初始的字符串长度就返回初始的
    if (endString.length >= S.length) {
      break;
    }
  }
  endString = endString.length >= S.length ? S : endString;
  return endString

};

```