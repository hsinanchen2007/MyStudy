*法一：二进制转十进制再转二进制，字符串太长，依然会碰到溢出的情况，故舍去*

```js
var addBinary = function(a, b) {
    var sum = parseInt(a,2) + parseInt(b,2)
    return sum.toString(2)
};
```

*法二：字符串左边padStart先补零，然后字符串相加，满二进一留零，满三进一留一*

```js
var addBinary = function(a, b) {
    var maxLen = Math.max(a.length,b.length);
    a = a.padStart(maxLen, '0')
    b = b.padStart(maxLen, '0')
    var temp = [];
    for(var i = 0; i < maxLen; i++) {
        temp.push(parseInt(a[i]) + parseInt(b[i]))
    }
    for(var j = maxLen - 1; j > 0; j--) {
        if(temp[j] == 2) {
            temp[j] = 0;
            temp[j-1] = temp[j-1] + 1;
        } else if (temp[j] == 3) {
            temp[j] = 1;
            temp[j-1] = temp[j-1] + 1;
        }
    }
    if(temp[0] == 2) {
        temp.splice(0,1,1,0);
    }
    if(temp[0] == 3) {
        temp.splice(0,1,1,1);
    }
    return temp.join('')
};

var a = '1111';
var b = '1111'
console.log(addBinary(a,b))
```
