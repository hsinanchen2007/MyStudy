### 解题思路
自己的代码太过繁琐

```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var arrs = s.split('');
    var len = arrs.length;
    // 创建堆栈
    var words = [];
    // 一定要先进行空字符串判断
    if(len == 0)
        return true;
    // 然后再进行非给定字符串判断，因为空字符串也满足下面的条件
    if(!(arrs[0] == '(' || arrs[0] == '{' || arrs[0] == '[')) {
        return false;
    }
    
    for(var i = 0; i < len; i++) {
        // 遇到左括号将其压入栈中
        if(arrs[i] == '(' || arrs[i] == '{' || arrs[i] == '[') {
            words.push(arrs[i]);
            // 遇到右括号判断是否跟栈顶是一对
        } else if(arrs[i] != getword(words.pop())) {
            return false;         
        }
    }
    return words.length == 0 ? true : false;
    
};
// switch是当满足case 条件时执行，没有遇到break就会一直执行下去
function getword(s) {
    var word;
    switch(s) {
        case '(':
            word = ')';
            // return ')' 是错的，因为没有break会继续执行接下来的语句
            // 就算加上break也不能使用return，因为return是在循环语句中使用的，不能在条件分支语句中使用
            break;
        case '{':
            word = '}';
            break;
        case '[':
            word = ']';
            break;
    }
    return word;
}
```
### 大神的代码
简洁，需要认真学习一下在很多判断条件时如何编写代码
```
var isValid = function (s) {
    let stack = []
    for (let c of s) {
        if (c == "(") stack.push(")")
        else if (c == "[") stack.push("]")
        else if (c == "{") stack.push("}")
        else {
            if (stack.length == 0) return false
            if (stack.pop() != c) return false
        }
    }
    return stack.length == 0
};
```
