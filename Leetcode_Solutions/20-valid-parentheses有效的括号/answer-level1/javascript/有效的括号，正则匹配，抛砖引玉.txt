看了很多栈的解法，自己也用栈实现过，随手写一个正则的方法，效率可能不太高，欢迎拍砖～

大致思路就是把对应的括号用正则匹配，然后去除

```js
var isValid = function(str){
    const reg = /(\(\)|\{\}|\[\])/;
    let temp = str;
    while(reg.test(temp)) {
        temp = temp.replace(reg, '');
    } 

    return !temp;
}
```
