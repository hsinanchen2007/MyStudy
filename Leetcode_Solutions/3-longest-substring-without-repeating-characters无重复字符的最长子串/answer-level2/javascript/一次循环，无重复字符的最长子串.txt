### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {

    let l = 0 
    let _s = ''
    for(let i = 0; i < s.length; i++) {
        let index = _s.indexOf(s[i])
        // 判断有没有重复的点
        if(index !== -1) {
            //当出现重复的点时，产生了个子串
             if(l < _s.length) l = _s.length
            // 新的串从重复点下一个开始截取
            _s = _s.slice(index + 1)
        }
        _s += s[i]
    }
    // 判断最后的子串是不是最长
    return l < _s.length ? _s.length : l
};
```