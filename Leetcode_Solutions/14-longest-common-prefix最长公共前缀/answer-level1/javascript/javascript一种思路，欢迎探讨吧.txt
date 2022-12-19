```
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) {
        return "";
    }
    if (strs.length === 1) {
        return strs[0];
    }
    if (strs[0] === "") {
        return "";
    }
    let [a, ...b] = strs, len = a.length, i = 1;
    while(i < len + 1) {
        let result = b.every((item) => {
            return item.indexOf(a.substring(0, i)) === 0
        })
        if (!result) {
            return a.substring(0, i - 1)
        }
        i++;
    }
    return a;
};
```
