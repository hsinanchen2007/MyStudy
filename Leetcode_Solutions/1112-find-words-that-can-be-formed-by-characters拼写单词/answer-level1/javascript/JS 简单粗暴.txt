执行用时 : 228 ms, 在所有 JavaScript 提交中击败了 70.00% 的用户
内存消耗 : 41.4 MB, 在所有 JavaScript 提交中击败了 100.00% 的用户

```javascript []
var countCharacters = function(words, chars) {
    var res = 0;
    for (let word of words) {
        let flag = true;
        let tchars = chars.split('');
        for (let ch of word) {
            if (tchars.includes(ch)) {
                tchars.splice(tchars.indexOf(ch), 1);
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            res += word.length;
        }
    }
    return res;
};
```
