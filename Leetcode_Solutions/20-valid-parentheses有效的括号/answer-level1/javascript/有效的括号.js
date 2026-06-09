```
/*
 * @lc app=leetcode id=20 lang=javascript
 *
 * [20] Valid Parentheses
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    var c = {
        '[': ']',
        '(': ')',
        '{': '}'
    };
    var a = s.split('');
    var b = [];
    for (let i = 0; i < a.length; i++) {
        if (c[b[b.length - 1]] == a[i]) {
            b.pop();
        } else {
            b.push(a[i]);
        }
    }
    if (b.length == 0) {
        return true;
    }
    return false;
};


```