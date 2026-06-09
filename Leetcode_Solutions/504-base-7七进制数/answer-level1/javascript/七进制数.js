*法一：常规进制转换*

```js
var convertToBase7 = function(num) {
    if (num == 0) return '0';
    let str = '';
    let radix = 7;
    let isPositiveNum = true;
    if(num < 0){
        num = -num;
        isPositiveNum = false;
    }
    while (num > 0) {
    	str = num % radix + str;
    	num = parseInt(num / 7);
    }
    return isPositiveNum ? str : '-' + str; 
};
```

*法二： 原生API*

Number.prototype.toString([radix])

```js
var convertToBase7 = function(num) {
    return (num).toString(7);
};
```

