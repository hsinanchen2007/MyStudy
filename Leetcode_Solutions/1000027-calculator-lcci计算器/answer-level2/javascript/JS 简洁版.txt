### 解题思路
&emsp;&emsp;大致思路说一下，把操作数存到栈中，因为只有加减乘除，所以只要优先处理乘除就好。当操作符号是乘除的时候，把前操作数弹栈与当前操作数进行运算后在压入栈，最后把所以操作数进行加减即可。（我当操作符是减号的时候压入的是负操作数，最后只需做累加即可）
### 代码
```javascript []
var calculate = function(s) {
    s = s.replace(/ /g,'');
    let numStr = '', lastSymbol = '', numStack = [];
    for(let i = 0; i <= s.length; i++){
        if(/[\+\-\*\/]/.test(s[i]) || i == s.length){
            switch(lastSymbol){
                case '*':
                    numStack.push(numStack.pop() * parseInt(numStr));
                    break;
                case '/':
                    numStack.push(~~(numStack.pop() / parseInt(numStr)));
                    break;
                case '-':
                    numStack.push(-parseInt(numStr));
                    break;
                default:
                    numStack.push(parseInt(numStr));
            }
            lastSymbol = s[i];
            numStr = '';
            continue;
        }
        numStr += s[i];
    }
    return numStack.reduce((_, val)=> _ + val, 0);
};
```
