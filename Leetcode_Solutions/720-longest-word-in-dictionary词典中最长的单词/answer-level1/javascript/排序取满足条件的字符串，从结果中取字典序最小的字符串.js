先按长度排序，得到结果数组后在按字典序排序

```javascript
/**
 * @param {string[]} words
 * @return {string}
 */
var longestWord = function(words) {
  let res = '';
  let resArr = [];

  // 将数组按长度，由大到小排序
  words.sort(function(a,b){ return b.length-a.length});

  // 遍历数组，依次检查是否符合条件
  
  for(let i = 0; i < words.length; i++){
    if(isAnswer(words, words[i])){
      if(resArr.length === 0 || words[i].length === resArr[resArr.length-1].length){
        // 将满足条件的长度最大的字符串放入新数组
        resArr.push(words[i]);   
      } else {
        // 长度不足，跳出循环
        break 
      }
    }
  }
  // 返回满足条件字符串中，字典序最小的字符串
  return resArr.sort(function(a, b){return a < b ? -1 : 1})[0];
};

/**
 * 字符串是否符合满足
 * @param {string[]} arr
 * @param {string} str
 * @return {boolean}
 */
function isAnswer(arr, str){
  let flag = true;  
  for(let i = str.length - 1; i > 0; i--){
    if(arr.indexOf(str.slice(0, i)) < 0){
      flag = false;
      break;
    }
  }
  return flag;
}
```