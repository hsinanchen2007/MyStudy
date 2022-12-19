1. 末位无进位，则末位加一即可，因为末位无进位，前面也不可能产生进位，比如 45 => 46

2. 末位有进位，在中间位置进位停止，比如 499 => 500

3. 末位有进位，并且一直进位到最前方导致结果多出一位，比如 999 => 1000


*法一：数组转化成Number，再加一，缺点，数组太长造成数字溢出，故舍去*


*法二：从后往前判断每位数是否为9*

```js
var plusOne = function(digits) {

    var len = digits.length;
    for(var i = len - 1;i >= 0;i--){
        if (digits[i] != 9){
            digits[i]++;
            break;
        }
        else {
            digits[i] = 0;
            if (i === 0) {
            	digits.unshift(1)
            }
        }
    }
    return digits
};

//var digits = [6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3];
var digits = [9,9];
console.log(plusOne(digits))
```

