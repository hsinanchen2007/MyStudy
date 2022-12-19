*法一：数字转化成字符串 + 数组的reverse方法*

```js
/**
 * @param {number} x
 * @return {number}
 */
 /*法一：借鉴数组的reverse方法*/
var reverse = function(x) {

    var arr = [];
    var stringX = String(x);
    var len = stringX.length;
    var newNum;

    for(let i = 0; i < len; i++) {
        arr.push(stringX[i])
    }
    
    if (stringX < 0) {
        arr.splice(0,1);
        arr.reverse();
        newNum  = Number('-' + arr.join(''))
    } else {
        arr.reverse();
        newNum = Number(arr.join(''))
    }

    if (newNum > 2147483647 || newNum < -2147483648) {
        return 0;
    } 
    return newNum;
    
};

var x = -5428514;
console.log(reverse(x))

```

*法二：数组存储每次的商【最高位上的数】*
```js
/*法二：数组存储每次的商【最高位上的数】*/
var reverse2 = function(x) {
    var flag = true;
    if (x < 0) { 
        flag = false;
    }
    var absX = Math.abs(x);
    // 被除数
    var divIdendX = absX;
    var i = absX.toString().length;
    var tempArr = [];
    var result;

   while(divIdendX > 0) {
        // 商
        var quotient = Math.floor(divIdendX / Math.pow(10,--i))
        divIdendX = divIdendX % Math.pow(10,i)

        tempArr.push(quotient)
    }

    tempArr.reverse();

    if (flag) {
        result = Number(tempArr.join(''))
    } else {
        result =  Number('-' + tempArr.join(''))
    }

    if (result > 2147483647 || result < -2147483648) {
        return 0;
    } 

    return result

}
var x = -5428514;
console.log(reverse2(x))

```

*法三：字符串拼接每次的余数【最低位上的数】*
```js

/*法三：字符串拼接每次的余数【最低位上的数】*/
var reverse3 = function(x) {

    var absX = Math.abs(x);
    // 被除数
    var divIdendX = absX;
    var l = absX.toString().length;
    var result = '';
    var i = 0;
    var quotient;

   while(i < l) {
        
        // 余数,每次个位数
        quotient = divIdendX % 10;
        //quotient = divIdendX.toString().substr(-1,1)
        
        divIdendX = Math.floor(divIdendX / 10)
        
        i++;

        result += quotient;
    }

    if (x < 0) {
        result = "-" + result;
    } 

    if (result > 2147483647 || result < -2147483648) {
        return 0;
    } 

    return result;

}
```

