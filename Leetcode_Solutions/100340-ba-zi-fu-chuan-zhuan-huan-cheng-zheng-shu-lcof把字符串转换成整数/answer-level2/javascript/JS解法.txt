### 代码

```javascript

var strToInt = function(str) {
    return Math.max(Math.min(parseInt(str) || 0, 2147483647), -2147483648)
};

```