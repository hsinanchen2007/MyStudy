算是动态规划吧

```js
var letterCombinations = function(digits) {
    let map = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    }
    let res = []
    let len = digits.length;
    if (len == 0) {
        return []
    } else {
        res[0] = map[digits[0]];
        for (let i = 1; i < len; i++) {
            res[i] = []
            for (let j = 0; j < res[i-1].length; j++) {
                for (let k = 0; k < map[digits[i]].length; k++) {
                    res[i].push(res[i-1][j] + map[digits[i]][k])
                }
            }
        }
        return res[len-1]
    }

};
```
