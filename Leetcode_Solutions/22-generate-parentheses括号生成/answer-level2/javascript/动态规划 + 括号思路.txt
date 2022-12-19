### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    return dp(n);

    function dp(n) {
        console.log(n)
        if (n == 0) return [];
        if (n == 1) return ['()'];
        if (n == 2) return ['(())', '()()'];

        var arr = [];
        console.log(n)
        for (var i = 3; i <= n; i++) {
            arr[i] = [];
            for (var j = 0; j < i; j++) {
                var p = dp(j);
                var q = dp(i - j - 1);
                
                if (p.length === 0) {
                    q.map(item => {
                        arr[i].push('()' + item);
                    })
                }

                if (q.length === 0) {
                    p.map(item => {
                        arr[i].push('(' + item + ')');
                    })
                }

                for (var qI of q) {
                    for (var pI of p) {
                        arr[i].push('('+ pI +')' + qI);
                    }
                }
            }
        }
        return arr[n];
    }
};
```