8行解决
```js
var lengthOfLongestSubstring = function(s) {
    let record = '', max = 0, index;
    for(let i = 0; i < s.length; i++) {
        index = record.indexOf(s[i]);
        record += s[i];
        if (index >= 0) record = record.substring(index + 1);
        else max = Math.max(max, record.length);
    }
    return max;
};
```
