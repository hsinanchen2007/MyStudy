# 解法一:暴力法
```
var isPerfectSquare = function (num) {
    var n = 1;
    while (true) {
        if (n * n == num) {
            return true;
        } else if ((n + 1) * (n + 1) > num) {
            return false;
        } else {
            n++;
        }
    }
};
```

# 解法二:玩数学
看了评论区大佬的提示，JS就可以一行解决
```
var isPerfectSquare = function (num) {
    return (num ** 0.5 % 1 == 0) ? true : false;
};
```
