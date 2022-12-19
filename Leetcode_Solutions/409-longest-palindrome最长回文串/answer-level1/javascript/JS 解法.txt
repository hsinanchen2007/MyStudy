```js
var longestPalindrome = function(s) {
    let map = new Map()
    let maxLen = 0
    for(let i of s) map.has(i)? map.set(i,map.get(i)+1):map.set(i,1)
    for(let [k,val] of map) maxLen += (val - val%2)
    return maxLen + (s.length - maxLen > 0)
};
```
