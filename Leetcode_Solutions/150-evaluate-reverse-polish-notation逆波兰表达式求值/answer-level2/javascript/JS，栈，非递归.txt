解题思路：遇到数字进栈，遇到运算符，在栈顶取两个值出栈，结合当前的运算符进行计算，计算结果入栈。最后循环结束返回栈顶元素。
```
/**
 * @param {string[]} tokens
 * @return {number}
 */

var calc = function(s1,s2,char){
    switch(char){
        case "+":return s1+s2;
        case "-":return s1-s2;
        case "*":return s1*s2;
        case "/":return (s1/s2)<=0?Math.ceil(s1/s2):Math.floor(s1/s2);
    }
}
var evalRPN = function(tokens) {
    let stack = [],
        len = tokens.length;
    let res = null;
    for(let i = 0;i<len;i++){
        if(tokens[i]==="+"
          ||tokens[i]==="-"
          ||tokens[i]==="*"
          ||tokens[i]==="/"){
            let s2 = stack.pop(),
                s1 = stack.pop();
            res = calc(s1*1,s2*1,tokens[i]);
            stack.push(res);
        }else{
           stack.push(tokens[i]); 
        }
    }
    return stack.pop();
};
```
