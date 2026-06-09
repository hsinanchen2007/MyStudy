这样写主要觉得写个字典有点low 不过空间复杂度只有 5% 是认真的吗
```javascript
/*
 * @lc app=leetcode.cn id=709 lang=javascript
 *
 * [709] 转换成小写字母
 */
/**
 * @param {string} str
 * @return {string}
 */
var toLowerCase = function(str) {
    let newStr = ''
    for(let i in str){
      let code = str[i].charCodeAt()
      if(code >= 65 && code <=90){
        newStr = newStr + String.fromCharCode(code + 32)
      } else {
        newStr = newStr + str[i]
      }
    }
    return newStr
};
// ✔ Accepted
//   ✔ 8/8 cases passed (60 ms)
//   ✔ Your runtime beats 98.53 % of javascript submissions
//   ✔ Your memory usage beats 5.16 % of javascript submissions (34.1 MB)
```