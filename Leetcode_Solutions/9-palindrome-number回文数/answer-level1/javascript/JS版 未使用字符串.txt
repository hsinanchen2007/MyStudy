
```js
var isPalindrome = function(x) {
    // 特例判断
    if (x === 10 || x < 0) return false;

    // 获取每一位的数字组成的数组，（尾递归优化）
    var loop = (n, arr = []) => {
        arr.push(n % 10);
        if (n >= 10) return loop((n - (n % 10)) / 10, arr);
        else return arr;
    };

    var tmp = loop(x);
    // 数组回文（下标）比较得到结果
    for (var i = 0, len = tmp.length; i < len / 2; i++)
        if (tmp[i] !== tmp[len - 1 - i]) return false;
    return true;
};
```
