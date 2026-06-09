### 解题思路
1.剔除非字母数字
2.reverse字符串
3.reverse前后比较
### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var filtet_out_s = filterOutString(s);
    var reverse_s = reverseString(filtet_out_s);
    return filtet_out_s.toLowerCase() == reverse_s.toLowerCase();
};

var filterOutString = function(s){
    return s.replace(/[^A-Za-z0-9]/g,"")
};

var reverseString = function(s){
    return s.split("").reverse().join("");
};
```