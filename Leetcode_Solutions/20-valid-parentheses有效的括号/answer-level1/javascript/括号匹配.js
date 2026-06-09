### 解题思路
相当于匹配括号，匹配到了就删除掉，如果有没匹配到的，证明字符串不正确。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 * '()()()',
 * '{{})})',
 * '{}{}{}()()()'
 *
 */
var isValid = function(s) {
  const leftJson = {
    ")":"(",
    "}":"{",
    "]":"["
  }
  const stack = []
  for(let j=0;j<s.length; j++){
    let c = s.charAt(j)
    if(c in leftJson){
      let tmp = stack.length != 0 ?  stack.pop() : 'xxxx'
      if(tmp != leftJson[c]){
        return false
      }
      
    }else{
      stack.push(c)
    }
  }
  return stack.length == 0
};
```