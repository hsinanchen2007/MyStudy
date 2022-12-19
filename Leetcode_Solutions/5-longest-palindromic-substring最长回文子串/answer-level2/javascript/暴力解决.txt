### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
// isPalindrome判断是否是回文串
var isPalindrome = function(str) {
  var len  = str.length
    var middle = parseInt(len/2)
    for(var i = 0;i<middle;i++){
        if(str[i]!=str[len-i-1]){
            return false
        }
    }
    return true
};
var longestPalindrome = function(s) {
    // 字符串长度小于1大于1000直接返回
    if (s.length <= 1 || s.length > 1000) {
        return s;
    }
    var longstr = "";
    // 最长的回文数
    var maxLength = 0;
    // 最长回文串的长度
    var len = s.length;
    ourfor:
    for (var i = 0; i < len; i++) {
        // 两个for循环依次切割字符串
        for (var r = i + 1; r <= len; r++) {
            // 如果截取字符串的长度小于最长回文串的长度，终止本次循环
            if (r - i < maxLength) {
                continue;
            }
            // 如果最长回文串的长度大于len-1,直接跳出循环
            // 因为从i开始截取的字符串不管如何长度都不会超过len-1
            if (maxLength > len - i) {
                break ourfor;
            }
            var tmpStr = s.substring(i, r);
            if (isPalindrome(tmpStr)) {
                // 如果截取的字符串是回文串，将longstr,maxLength替换
                longstr = s.substring(i, r);
                maxLength = tmpStr.length;
            }
        }
    }
    return longstr;
};
```