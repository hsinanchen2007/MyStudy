这个题有一个很简单很暴力的方式解决：
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var map = {
        'E':0,
        'I':1,
        'V':5,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000
    }
    s = s + 'E';
    var res = 0;
    for(let i = 0, len = s.length - 1; i < len; i++) {
        if(map[s[i]] >= map[s[i+1]]) {
            res += map[s[i]];
        } else {
            res += map[s[i+1]] - map[s[i]];
            i++;
        }
    }
    return res;
};
```
在字符串最后加入一个结束字符E，在map中将它的值定义为0（0比任何其他字符的值都小），然后遍历整个字符串。
从题干可以知道，左边的罗马数字比右边大的话，那么是相加，否则就是相减。
所以遍历整个字符串，每个字符与其下一个字符做比较，大则相加，小则用下一个字符的值减去当前字符，且跳过下一个字符，直到遍历完整个数组，遇到结束字符E，由于E肯定比所有的罗马数字的值都小，因此直接加上E之前一位的值。