1个括号的时候必然是 "()"
2个括号的时候就是在一个括号的基础上再加一个括号，加在哪里呢？任意的位置，只要保证新加的括号在一起就行
所以就有了三种情况 "()()", "(())", "()()" 其中第一种中情况和第三种重复了，去掉即可。
第三个括号时候 在"()()", "(())"的基础上加一个完整的括号，其中第一中加完的结果为
"()()()"、"(())()"、"()()()"、"()(())"、"()()()"
其他的就不演示了，虽然新加的括号是不分开的，但是它有机会使上一级的括号变成外层括号，所以可以涵盖任何满足括号原则的情况。
是不是容易理解些呢？
```
var generateParenthesis = function(n) {
    if(n == 0){
        return [""];
    }
    let previous = generateParenthesis(n-1), next = [], temp;
    for(var i = previous.length-1; i>=0; i--){
        temp = previous[i];
        for(var j = temp.length; j >= 0; j--){
            next.push(temp.slice(0,j) + "()" + temp.slice(j));
        }
    }
    next = [...new Set(next)];
    return next;
```
