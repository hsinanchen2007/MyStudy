```
/**
 * @param {string[]} strs
 * @return {string}
 */
//1
var longestCommonPrefix = function(strs) {
    return strs.length == 0 ? "" : strs[0].split("").reduce((res, s, idx) => {
        return res = res.length >= idx ? strs.every((item) => {
            return item[idx] == s
        }) ? res.concat(s) : res : res
    }, "")
};
//1
var longestCommonPrefix = function(strs) {
    if(strs.length==0) return ""
    for(let i=0;i<strs[0].length;i++){
        if(!strs.every((item) => {
            return item[i] == strs[0][i]
        })) return strs[0].substring(0,i)
    }
    return strs[0]
};
```
