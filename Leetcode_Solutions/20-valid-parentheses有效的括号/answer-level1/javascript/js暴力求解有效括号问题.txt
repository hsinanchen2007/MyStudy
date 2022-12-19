### 解题思路
此处撰写解题思路
简单粗暴方式，判断字符是否是关闭括号，如果是关闭符号，拿出栈顶符号进行比较，如果匹配成功，则直接出栈，如果没有匹配上，就直接压栈。一次遍历之后，判断栈的深度，栈空则返回true否则返回false

js String相应API为str.chatAt(index)

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {

  const length = s.length;
  let stack =[];
  let i = 0;
  let map={
      ')':'(',
      ']':'[',
      '}':'{',
  }
  for(;i<length;i++){
      let char = s.charAt(i)
      if(map[char]){ // 关闭
          let top = stack[stack.length-1]
          if (map[char] === top){
              stack.pop()
          }else {
              stack.push(char)
          }
      }else {
         stack.push(s.charAt(i)) 
      }
  }
  return stack.length ===0
};
```