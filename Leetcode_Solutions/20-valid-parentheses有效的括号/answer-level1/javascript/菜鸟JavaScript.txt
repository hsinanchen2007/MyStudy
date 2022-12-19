### 解题思路
需要注意两点：
1、这里的replace() 方法用于在字符串中用一些字符替换另一些字符，或替换一个与正则表达式匹配的子串
2、当循环的次数确定时，使用for循环和while循环差别不大，但是当循环次数不确定时，while方法使用起来更加方便，更加好理解。


————————————————
版权声明：本文为CSDN博主「吉帅振」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_42451979/article/details/80913937

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    while (s.length) {
        var Str = s;
        s = s.replace('()', '');
        s = s.replace('[]', '');
        s = s.replace('{}', '');
        if (s === Str) return false
    }
    return true;
};
```