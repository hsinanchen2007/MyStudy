```
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    haystack = haystack.replace(needle, '*');
    var ist = '-1';
    for(var i = 0; i < haystack.length; i++){
        if(haystack[i] === '*'){
            ist = i;
        }
    }
    return ist;
};
```
