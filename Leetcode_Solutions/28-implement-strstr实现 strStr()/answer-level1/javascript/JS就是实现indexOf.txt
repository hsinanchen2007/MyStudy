思路：
    按照js的思路实际上就是实现indexOf,直接用indexOf就没有意义了。

```js
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    var needleL = needle.length
    var haystackL = haystack.length
    if((needle == haystack) || (haystackL && !needleL)) {
      return 0       
    }
    if((!haystackL && needleL)) {
      return -1    
    } 
    for (var i=0;i<haystackL;i++){
        if(haystack.slice(i,i+needleL) == needle) {
            return i
        }
    }
    return -1

};
```