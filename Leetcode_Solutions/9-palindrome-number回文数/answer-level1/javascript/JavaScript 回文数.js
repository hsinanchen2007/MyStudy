> 和「整数反转」几乎一样的思路，看了官方题解为了避免溢出**反转一半数字**，发现我的解法**把每一位都保存下来**刚好避免了这种问题。
> 
> 不过有得必有失，数组占用的空间较大。虽然按照要求没有用到字符串，但用数组逐位保存实际上还是字符串的思想，算是钻了空子。

```js
var isPalindrome = function (x) {
    if (x < 0) return false;
    var arr = [];
    var i = 0;
    while (parseInt(x / 10)) {//123->12
        arr[i] = x - 10 * parseInt(x / 10);
        x = parseInt(x / 10);
        i++;
    }
    var l = i;
    arr[i] = x;
    for (; i >= l / 2; i--) {
        if (arr[i] != arr[l - i]) return false;
    }
    return true;
};
```