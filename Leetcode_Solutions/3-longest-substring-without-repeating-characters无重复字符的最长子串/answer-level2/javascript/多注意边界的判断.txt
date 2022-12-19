```
/**
    * @param {string} s
    * @return {number}
    */
    // "abcabcbb"
    // "bbbbb"
    // "pwwkew"
    var lengthOfLongestSubstring = function(s) {
    if(s.length > 1) {
        let str = s[0]; // 临时存储子串
        let longLen = 0; // 存储最长子串的长度
        for (let i = 1, len = s.length; i < len; i++) {
            let index = str.indexOf(s[i]);
            if(index === -1) {
                str = str + s[i];
                if(str.length > longLen) {
                    longLen = str.length;
                }
            } else {
                // 有存在重复的字符了
                if(str.length > longLen) {
                    longLen = str.length;
                }
                if(index === (str.length - 1)) {
                    str = s[i];
                } else {
                    str = str.substr(index + 1) + s[i];
                }
            }
            if(longLen === 0 && i === len - 1) {
                longLen = str.length;
            }
        }
        return longLen;
    } else {
        return s.length;
    }
}
```
