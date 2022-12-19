```js
var findContentChildren = function(g, s) {
    // 贪心思想, 优先满足胃口小的孩子

    let res = 0;

    s = s.sort((a, b) => a - b);

    g.sort((a, b) => a - b).forEach(item => {
        while (s.length) {
            if (item <= s.shift()) {
                res++;
                break;
            }
        }
    });

    return res;
};
```
