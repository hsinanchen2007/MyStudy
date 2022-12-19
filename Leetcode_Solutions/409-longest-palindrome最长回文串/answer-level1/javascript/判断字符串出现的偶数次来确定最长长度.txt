```
var longestPalindrome = function(s) {
    let len = s.length;
    if (!len) return 0;
    let i = 0;
    let max = 0;
    let temp = {};
    while (i < len) {
        let curr = s.charAt(i);
        if (temp[curr] >= 0) {
            temp[curr]++;
            if (temp[curr] === 2) {      // 记录字符出现偶数次数的个数，出现偶数一定能组成回文字串
                max += 2;
                temp[curr] = 0;
            }
        } else {
            temp[curr] = 1;
        }
        i++;
    }
    return max === len ? max : 1 + max; // 最长长度如果与字符串长度相等，说明都是出现偶数次数，若不相等，则在此基础上加1
};
```
