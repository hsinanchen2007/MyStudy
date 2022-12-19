*法一：while+while，每次取余数相加*

```js
var addDigits = function(num) {
    while (num > 9) {
        var i = 0;
        var l = num.toString().length;
        // 被除数
        var divIdendX = num;
        // 余数
        var quotient;
        var sum = 0;
        while(i < l) {
            // 每次求的最右边位上的这个数
            quotient = divIdendX % 10;
            divIdendX = Math.floor(divIdendX / 10)
            i++
            sum += quotient
        } 
        num = sum
    }
    return num
};
var num = 19;
console.log(addDigits(num));
```

*法二：while+for，借用数组*

```js
var addDigits2 = function(num) {
    while (num > 9) {
        var str = num.toString();
        var sum = 0;
        for(let i = 0; i < str.length; i++) {
            sum += parseInt(str[i])
        }
        num = parseInt(sum)
    }
    return num
};
```

*法三：一次for循环，加的时候超过10就减9*

```js
var addDigits3 = function(num) {
    var sum = 0;
    var str = num.toString();
    for(let i = 0; i < str.length; i++) {
        sum += (str[i]) * 1;
        if (sum >= 10) {
            sum -= 9
        } 
    }
    return sum
};
```

*法四：借助数组的reduce方法*

```js
var addDigits4 = function(num) {
    while (num > 9) {
        num = num.toString().split('').reduce((a, b) => parseInt(a) + parseInt(b))
    }
    return num
};
```

