标准的滑动窗口问题

要找的子字符串必然存在与原字符串中


```js

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let res = 0;
    let cur = "";
    //遍历字符串
    for(let i of s){
        let index = cur.indexOf(i);
        res = Math.max(res,cur.length);
        cur = cur + i;
        cur = cur.slice(index+1);
    }
    return Math.max(res,cur.length);
};

```
