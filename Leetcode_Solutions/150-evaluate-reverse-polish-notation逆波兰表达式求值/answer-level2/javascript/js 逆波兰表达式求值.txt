    由题可知，逆波兰表达式的求值其实就是：
        1. 运算符号的前两个元素进行运算；
        2. 如果说运算符号前两个元素并非都是数字，那么也肯定可以通过前面的运算将其变为数字。
    基本思路就是通过一次次改变当前数组，将类似于<"13", "5", "+">这样的连续元素循环替换为运算结果，最后数组中就只剩一个元素，那么改元素就是运算结果。
    如：
        *
            1. ["4", "13", "5", "/", "+"]
            2. ["4", 2, "+"]
            3. [6]
        *
```
/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    var i=2;
    while (tokens.length > 1){
        if(tokens[i] === '+'){
            tokens.splice(i-2, 3, parseInt(tokens[i-2]) + parseInt(tokens[i-1]));
            i-=2;
        }else if(tokens[i] === '-'){
            tokens.splice(i-2, 3, parseInt(tokens[i-2]) - parseInt(tokens[i-1]));
            i-=2;
        }else if(tokens[i] === '*'){
            tokens.splice(i-2, 3, parseInt(tokens[i-2]) * parseInt(tokens[i-1]));
            i-=2;
        }else if(tokens[i] === '/'){
            tokens.splice(i-2, 3, parseInt(parseInt(tokens[i-2]) / parseInt(tokens[i-1])));
            i-=2;
        }
        i++;
    }
    return tokens[0];
};
```

