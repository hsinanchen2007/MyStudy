### 解题思路
方法一、普通解法：

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    var arr = [];
    for(var i=1;i<=n;i++){
        if(i%3==0 && i%5!=0){
            arr.push('Fizz');
        }
        else if(i%3!=0 && i%5==0){
            arr.push('Buzz');
        }
        else if(i%3==0 && i%5==0){
            arr.push('FizzBuzz');
        }
        else {arr.push(i.toString());}
        //arr[i]=i.toString();
    }
    return arr;
};
```
方法二、改进解法：拼接字符串
```
var fizzBuzz = function(n) {
    var arr=[];
    for(var i=1;i<=n;i++){
        var str = "";
        if(i%3==0){
            str += "Fizz";
        }
        if(i%5==0){
            str += "Buzz";
        }
        if(str==""){
            str += i.toString();
        }
        arr.push(str);
    }
    return arr;
};
```

