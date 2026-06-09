```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
  let bracketObj = {
    ')': '(',
    '}': '{',
    ']': '[',
  }
  let arr = [...s]
  let stack = []
  // try catch 来跳出foreach 循环，因为foreach里用return只会跳出当次循环
  try{
    arr.forEach(e => {
      if(!bracketObj[e]){
        stack.push(e)
      }else if(bracketObj[e] && bracketObj[e] !== stack.pop()){
        throw new Error()
      }
    })
  }catch(e){
    return false
  }
  // 判断正确：栈空
  return !(stack.length)

};
```
思路
  
1.存以右括号为key，做括号为value的一个对象
2.每次看看是否在这个对象里有key，如果没有代表的是做括号，入栈
3.如果有则代表他是右括号，需要出栈一个元素与该值判断是否相等，如果不等代表左括号类型不一样，报错，从try catch跳出
4.判断正确的逻辑：栈空

时间复杂度/空间复杂度： O(n)/O(n) 
  