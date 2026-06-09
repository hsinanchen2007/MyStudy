### 解题思路
![image.png](https://pic.leetcode-cn.com/2fbca9f2a1004a4eb03e3bb5b78590295f6e0535cbacb217c6cf9b6e81e021ca-image.png)


### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */

var strStr = function(haystack, needle) {
    if( !needle || haystack == needle ) return 0
    const len = needle.length
    for( let i = 0; i<haystack.length - len + 1; i++){
        if( haystack.substr(i, len ) == needle ){
            return i
        }
    }
    return -1
};


// em... 
// var strStr = function(haystack, needle) {
//     return haystack.indexOf(needle)
// };
```