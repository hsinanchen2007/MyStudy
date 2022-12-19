### 解题思路
遍历循环hasstack,如果hasstack的第i项等于needle的第一项，就截取hasstack的i-needle.length长度的字符串，看是否与needle相等，如果相等，就返回i;如果不相等就继续循环，知道找到相等时的i；
如果循环到最后还是找不到匹配的字符串，则返回-1。

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
    if (needle == '') return 0;
    if (needle.length > haystack.length) return -1;
    for(let i = 0; i< haystack.length;i++) {
        if(haystack[i] == needle[0]) {
            if(haystack.substring(i,i+needle.length) === needle) return i;
        }
    }
    return -1;
};
```