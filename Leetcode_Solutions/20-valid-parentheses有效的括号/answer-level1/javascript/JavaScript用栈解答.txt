### 解题思路
先判断如果为偶数个直接返回false，再遵循见左括号进栈，见右括号与栈顶比较，非闭合关系，则直接返回false，闭合，则出栈...最后栈为空，则整体返回true。

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
   //奇数个直接返回false
   if (s.length%2!==0) return false;
   //便于判断是否是右括号，且是否与栈顶是闭合关系
   var obj = {'}':'{',')':'(',']':'['};
   var stack = [];  
   for(var i =0;i<s.length;i++){
       var tmp = obj[s[i]];
        //tmp为undefined则为左括号，反之则为右括号
       if(tmp){
           if(stack[0]!=tmp)return false;
           stack.shift();
       }
       else{
           stack.unshift(s[i]);
       }     
   }
   return (stack.length===0);
};
```
有没有更简洁的方法呢？