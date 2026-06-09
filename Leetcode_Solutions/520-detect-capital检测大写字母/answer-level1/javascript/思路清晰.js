### 解题思路
分两种情况
1. 当第一个字符是大写时，后面的所有字符必须一致(都是大写，或者都是小写)
2. 第一个字符不是大写时，整个字符串必须一致(都是小写)
### 代码

```javascript
var detectCapitalUse = function(word) {
    let n = word.length;

    if (n <= 1) return true;
    let first = word[0];

    return first.toUpperCase() == first ? help(word.substring(1)) : help(word);
};
// 判断字符中是否全部都是某一种写法
function help(s) {
    let upper = s.toUpperCase() == s;
    let lower = s.toLowerCase() == s;

    return upper || lower;
}

```