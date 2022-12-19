### 解题思路
一开始想到的也是栈的结构可以解决这个问题，即后进先出，不过也还是看了官方解释才挤出代码来的。。
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let len = s.length;
    if(len % 2 !== 0){ return false; }
    let stack = [];
    let obj = { ')': '(', ']': '[', '}': '{'}
    if(s === ''){ return true;}
    for(let i = 0; i<len; i++){
        if(s[i] === '(' || s[i] === '[' || s[i] === '{'){
            stack.push(s[i])
        }else{
            let v = stack.pop();
            if(obj[s[i]] !== v){
                return false;
            }
            // switch(s[i]){
            //     case ')': 
            //         if(v !== '('){ return false; }
            //         break;
            //     case ']': 
            //         if(v !== '['){ return false; }
            //         break;
            //     case '}': 
            //         if(v !== '{'){ return false; }
            //         break;
            // }
        }
    }
    return !stack.length;
};
```