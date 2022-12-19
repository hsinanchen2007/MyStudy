11行代码
```js
/**
 * @param {number} num
 * @return {number}
 */
var translateNum = function(num) {
    let str = '' + num;
    let res = 0;
    function dfs(i) {
        if (i >= str.length) res++;
        else {
            dfs(i + 1);
            if (+str[i] && +(str[i] + str[i + 1]) < 26) dfs(i + 2);
        }
    }
    dfs(0);
    return res;
};
```
