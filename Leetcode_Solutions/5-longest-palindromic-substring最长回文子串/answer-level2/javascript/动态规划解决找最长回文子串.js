刚开始我完全没有思路，看了官方的题解。根据官方的动态规划思路，编写代码。
```
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
    if (s.length < 2) {// 长度小于2，最长回文子串就是它本身
        return s;
    } else {
        var dp = [], right = 0, left = 0;
        for (let i = 0; i < s.length; i++) {
            dp[i] = []; // 初始化为二维数组，s[i][j]记录字符串下表从j到i是否是回文
        }
        for (let i = 0; i < s.length; i++) {
            dp[i][i] = true;// 字符本身是回文
            for (let j = i - 1; j >= 0; j--) { // 反向查找是否为回文
                dp[i][j] = s[i] === s[j] && (i - j === 1 || dp[i - 1][j + 1]);
                if (dp[i][j] && i - j > right - left) {
                    right = i;
                    left = j;
                }
            }
        }
        return s.slice(left, right + 1);
    }
};
```
