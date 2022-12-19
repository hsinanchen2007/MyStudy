### 解题思路
记录平滑时出现的最高长度，每次比较最新值有无出现重复值。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let i = 0;
    let j = 1;
    let str = '';
    let len = 0;
    while(j<=s.length){
        str = s.slice(i,j);
        if(str.indexOf(s[j])>-1){
            i++;
            j--;
        }
        if(str.length>len){len = str.length}
        j++;
    }
    return s.length===1?1:len;
};
```