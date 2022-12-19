*法一：*

```js
var arrangeCoins = function(n) {
    let arr = [0];
    let i = 1;
    while(arr[arr.length-1] < n) {
        arr.push(arr[arr.length-1]+i)
        i++
    }
    return arr[arr.length-1] === n ? arr.length-1 : arr.length - 2
};
```

*法二*

思路： 

用硬币数不断减去当前行，得到剩余硬币数，只有当剩余硬币数大于当前行时，说明他还能排满下一行，则行数+1， 不满足的时候说明剩余硬币不够排满下一行了

```js
var arrangeCoins = function(n) {
    var line = 0 // 当前排满硬币的行
    while(n > line) {
        line++;
        n = n - line;
    }
    return line
};
```

