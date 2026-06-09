数据太弱了, 解法不值得参考

```
/**
 * @param {string} s
 * @return {string}
 */
var longestPrefix = function(s) {
    if (s.length <= 1) {
        return '';
    }
    for (let i = s.length - 1; i > 0; i--) {
        if (s.slice(0, i) === s.slice(s.length - i)) {
            return s.slice(0, i);
        }
    }
    return '';
};
```

我的所有题解 <https://github.com/yinxin630/leetcode>