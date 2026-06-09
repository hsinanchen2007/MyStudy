```
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let len = s.length, freq = {}, res = 0, l = 0, r = -1
    for(let i of s) {
        freq[i] = 0
    }
    while(l < len) {
        if((freq[s[r+1]] === 0) && r + 1 < len){
            freq[s[++r]]++
        } else {
            freq[s[l++]]--
        }
        res = Math.max(res, r - l + 1)
    }
    return res
};
```
