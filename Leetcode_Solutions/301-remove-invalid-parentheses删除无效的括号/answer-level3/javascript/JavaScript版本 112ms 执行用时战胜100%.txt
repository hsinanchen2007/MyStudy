```javascript
// 1. 先将字符串处理一下 将开头的 ')' 和结尾的 '(' 删除
//     例如   'aa)()(ff' 处理成   'aa()ff'
// 2. 算出这个字符串到底需要删除几个 '(' 和几个 ')' 
//     例如  aa())(() 需要删除一个（和 一个）得到  aa()()
// 3.编写递归 知道了左右括号个被删除几次 当删除 完成时 就可以使用当前字符串加上剩余字符串  然后判断是否成立
// 4. 数组去重 有可能会有多个相同的 答案被添加到数组
var removeInvalidParentheses = function(s) {
  // 先将字符串处理一下 将开头的 ')' 和结尾的 '(' 删除
  let left = 0;
  let right = 0;
  let length = s.length;
  while(left >= 0 && left < length  && s[left] !== '(') {
    if(s[left] === ')') {
      s = s.slice(0, left) + s.slice(left+1)
      length--;
    } else {
      left++
    }
  }
  while(length-right-1 >= 0 && -1 < right && s[length-right-1] !== ')') {
    if (s[length-right-1] === '(') {
      s = s.slice(0, length-right-1) + s.slice(length-right)
      length--;
    } else {
      right++;
    }
  } 
  if (length === 0) return ['']
  if (length === 1 && s[0] !== ')' &&  s[0] !== '(') return [s];
  // 算出这个字符串到底需要删除几个 '(' 和几个 ')' 
  let delLeft = 0;
  let delRight = 0;
  let number = 0;
  let result = [];
  for (let i = 0; i < length; i++) {
    if (s[i] === '(') number++
    else if (s[i] === ')') number--;
    if (number === -1) {
      delRight += -1;
      number = 0;
    }
  }
  let isValid = function(s) {
    let number = 0;
    for (let i = 0, len = s.length; i < length; i++) {
      if (s[i] === '(') number++
      else if (s[i] === ')') number--;
      if (number === -1) {
        return false;
      }
    }
    return number === 0;
  }
  if (number > 0) delLeft = number;
  else delRight += number;
  // 编写递归 知道了左右括号个被删除几次 当删除 完成时 就可以使用当前字符串加上剩余字符串  然后判断是否成立 
  let helper = function(str, number, len, delLeft, delRight) {
    if (number < 0 || len > length) return;
    if (delLeft === 0 && delRight === 0 ) return isValid(str + s.slice(len)) && result.push(str + s.slice(len));
    if (s[len] === '(') {
      helper(str+'(', number+1, len+1, delLeft, delRight)
      delLeft > 0 && helper(str, number, len+1, delLeft-1, delRight)
    } else if (s[len] === ')') {
      helper(str+')', number-1, len+1, delLeft, delRight)
      delRight > 0 && helper(str, number, len+1, delLeft, delRight-1)
    } else {
      helper(str+s[len], number, len+1, delLeft, delRight)
    }
  }
  helper('', 0, 0, delLeft, -delRight);
  // 数组去重 有可能会有多个相同的 答案被添加到数组
  result.sort()
  for (let i = 1, len = result.length; i < len; i++) {
    if (result[i] === result[i-1]) {
      result.splice(i, 1);
      i--;
      len--;
    }
  } 
  return result;
};
```