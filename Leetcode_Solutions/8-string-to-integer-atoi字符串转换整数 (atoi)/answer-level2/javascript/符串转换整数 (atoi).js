### 代码

```javascript
var myAtoi = function(str) {
    str = str.replace(/^\s+/, '').replace(/\s+$/, '')
    let num = parseInt(str)
    if (isNaN(num)) {
        return 0
    } else if (/^[\d\+]/.test(num)) {
        return Math.min(num, Math.pow(2,31)-1)
    } else {
        return Math.max(num, -Math.pow(2,31))
    }
};
```