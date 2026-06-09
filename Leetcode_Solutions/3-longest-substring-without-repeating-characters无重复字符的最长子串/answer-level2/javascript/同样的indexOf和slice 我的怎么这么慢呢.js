### 解题思路
同样的用indexof,slice怎么我的怎么慢呢

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let l = 0;
    let cs = '';
    for(let o of s) {
        const i = cs.indexOf(o);
        if(i !== -1) cs = cs.slice(i + 1);
        cs += o;
        l = cs.length > l ? cs.length : l;
    }
    return l;
};
```