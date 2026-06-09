```
// 判断奇数字符串的个数长度为：总字符数 - 奇数数量的字符种类数 + 1 (区分大小写)
var longestPalindrome = function(s) {
    let map = new Map();
    let lenS = s.length;
    let numOdd = 0; // 记录奇数的个数
    for(let i of s) {
        if(!map.get(i)) {
            map.set(i, 1);
        } else {
            map.set(i, map.get(i) + 1);
        }
    }
    for (let [key, value] of map.entries()) {
        if(value % 2 === 1) {
            numOdd += 1;
        }
    }
    if (numOdd === 0) {  // 全都是偶数个的情况 自身就是回文子串
        return lenS
    } else { // 最长回文子串长度：总字符数 - 奇数数量的字符种类数 + 1 (区分大小写)
        return lenS - numOdd + 1;
    }
};
```
