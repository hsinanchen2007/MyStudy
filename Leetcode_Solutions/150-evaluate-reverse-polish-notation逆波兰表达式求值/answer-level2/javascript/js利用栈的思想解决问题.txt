### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/12a902b3dfb06f8d1e0197ff49374e1d33f889bbfacab54cb79898759baa4fcc-%E6%8D%95%E8%8E%B7.PNG)

依次便利tokens，然后把找到的数字入栈，遇到运算符，弹出栈顶两个数字，参与概运算，最后栈中只会留下一个数字，这个数字就是运算结果

### 代码

```javascript
/**
 * @param {string[]} tokens
 * @return {number}
 */
var operation={
    '+' : (a,b) => (a)+(b),
    '-' : (a,b) => (a)-(b),
    '*' : (a,b) => (a)*(b),
    '/' : (a,b) => (a)/(b) | 0
}

var evalRPN = function(tokens) {
    var stack=[];
    for(var i=0;i<tokens.length;i++){
        var item=tokens[i];
        if(!(item in operation)){
            stack.push(item);
        }else{
            var value1=+stack.pop();
            var value2=+stack.pop();
            var result=operation[item](value2,value1);
            stack.push(result+'');
        }
    }

    return stack[0];
};
```