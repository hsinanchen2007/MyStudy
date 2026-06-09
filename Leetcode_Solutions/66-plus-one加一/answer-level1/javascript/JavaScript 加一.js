解一（伪）：
> 将数组转换为数字再加一，然后将数字转换回数组。问题是当数字过大时会造成溢出。

```js
var plusOne = function(digits) {
    var number = 0;
    for(var digit of digits){
        number = number*10 + digit
    }
    number = (++number).toString();
    number = number.split('').map(Number)
    return number
};
```

解二：
> 既然题目已经将数字每一位都分解好了，直接在数组上操作十进制的计算相对更加容易。

```js
var plusOne = function(digits) {
    var len = digits.length;
    for(var i = len-1;i>=0;i--){
        if (digits[i]!=9){
            digits[i]++;
            break;
        }
        else {
            digits[i]=0;
            if (i===0) digits.unshift(1)
        }
    }
    return digits
};
```