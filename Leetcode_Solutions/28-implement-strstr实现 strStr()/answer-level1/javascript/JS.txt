### 解题思路
两种方法（注释的是方法二）

### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let len = needle.length;
    if(len <= 0){
        return 0;
    }
    for(let i = 0; i < haystack.length; i++){
        if(needle[0] == haystack[i]){
            if(haystack.slice(i, i + len) == needle){
                return i;
            }
            // let flag = true;
            // for(let j = 0; j < len; j++){
            //     if(!haystack[i+j] || needle[j] != haystack[i+j] ){
            //         flag = false;
            //     }
            // }
            // if(flag){
            //     return i;
            // }
        }
    }
    return -1;
};
```