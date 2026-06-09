### 解题思路
开始思路也是从中间向两边扩展，但是无奈自己的方法比较笨，挨个检测合法性，导致无法通过性能测试。
看了官方题解，优化了判断，同时每次找到奇数与偶数的最长串，效率提高

### 代码

```javascript
/**
 * 5. 最长回文子串
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {

    let res = '';

    
    for (let i = 0; i < s.length; i++) {
        let len1 = findLongestAround(s, i, i); //奇数
        let len2 = findLongestAround(s, i, i + 1) //偶数
        let len = Math.max(len1, len2);
        if(len > res.length) {
            res = s.substr(i - Math.floor((len - 1) / 2), len);
        }
    }

    return res;
};

function testPalindrome(str) {
    let reverse = [...str].reverse().join('');
    return reverse == str;
}

function findLongestAround(str, left, right) {

    while (left >= 0 && right < str.length && str.charAt(left) === str.charAt(right)) {
        left--;
        right++;
    }
    //这里-1
    return right - left - 1;
}
```