```js
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    var result = '';
    var len = strs.length;
    if (!len) {
        return result;
    }
    if (strs.length == 1) {
        return strs[0];
    };
    var firstLen = strs[0].length;
    for(let i = 0; i < firstLen; i++) {
        for (let k = 1; k < len; k++) {
            if(strs[0][i] !==  strs[k][i]) {
                return result;
            }
        }  
        result += strs[0][i];
    }
    return result;
};

var strs = ["flower","flow","floight"];
//var strs = ["dog","racecar","car"]

console.log(longestCommonPrefix(strs))
```