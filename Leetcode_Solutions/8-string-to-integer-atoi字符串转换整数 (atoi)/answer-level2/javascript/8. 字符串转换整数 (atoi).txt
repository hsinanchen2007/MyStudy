
# JavaScript一句过~
```
var myAtoi = function(str) {
    return Math.max(Math.min(parseInt(str.trim().match(/^[+|-]?\d+/)||0), Math.pow(2,31)-1), -Math.pow(2,31))
};
```

# 拆解

这样拆解开会稍微提速一下吧
```
var myAtoi = function(str) {
    str = str.trim();
    if(!/^[+|-]?\d+/.test(str)) return 0;
    let val = parseInt(str.match(/^[+|-]?\d+/));
    let base = Math.pow(2,31)
    let min = -base;
    let max = base-1;
    return Math.max(Math.min(val, max), min)
};
```
