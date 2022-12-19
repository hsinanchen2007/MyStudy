解一：
> 使用JavaScript内置的`toString`和`parseInt`进行进制转换。
> 整个过程的流程：`十进制数字->二进制字符串->二进制数组->首位补0->二进制数组反转->二进制字符串->十进制数字`

```js
var reverseBits = function(n) {
    n = n.toString(2);
    n = n.split('')

    while(n.length<32){
        n.unshift('0')
    }

    var start = 0;
    var end = 31;

    while(start<end){
        var temp = n[start];
        n[start++]=n[end];
        n[end--]=temp;
    }

    return parseInt(n.join(''),2)
};
```

解二：
> 手动进制转换。
> 整个过程的流程：`十进制数字->二进制数组->首位补0->十进制数字`
> 因为十进制转二进制是逐次求余再倒序拼接余数，这里我们可以直接利用数组的下标和位数呈互补关系进行进制转换，不需要再倒序。

```js
var reverseBits = function(n) {
    var bin = [];
    while (n){
        bin.unshift(n%2);
        n = parseInt(n/2);
    }
    while (bin.length<32) bin.unshift(0);
    
    var re = 0;
    for (var i=0; i<32; i++){
        re += bin[i]*Math.pow(2,i);
    }
    return re;
};
```

解三：
> 在解二的基础上进行简化，去掉了保存每一位和补0的过程，直接在循环中进行累加。

```js
var reverseBits = function(n) {
    var re = 0;
    var count = 0;
    while (n){
        re += (n%2)*Math.pow(2,32-++count);
        n = parseInt(n/2);
    }
    return re;
};
```
![](https://pic.leetcode-cn.com/71ac31d24c0b7f5a66c79938c7f940e3fc19732441b0b99bd78931bb294908e7-file_1568435602442)