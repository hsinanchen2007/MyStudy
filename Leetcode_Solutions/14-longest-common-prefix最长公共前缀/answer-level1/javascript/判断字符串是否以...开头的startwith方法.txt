
```
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length == 0)
        return '';
    var str = strs[0].split('');
    var len = strs.length;
    var l = str.length;
    var common = '';
    var c = '';
    for(var i = 0; i < l; i++) {
        c += str[i];
        for(var j = 1; j < len; j++) {
            // 不能用索引值indexof作为条件，因为在字符串中存在多个对应字符的情况下，判断条件会为假
            // 使用startwith的方法，可以判断某个字符串是否以某段字符开头，返回布尔值
            if(!(strs[j].startsWith(c))) {
                return common;
            }
        }
        common += str[i];
    }
    return common;
};
```
### 大神的简洁版代码
```
var longestCommonPrefix = function (strs) {
    let ans = strs.length > 0 ? strs[0] : ""
    for (let i = 1; i < strs.length; i++) {
        if (!strs[i].startsWith(ans)) {
            for (let j = 0; j < ans.length; j++) {
                if (ans[j] != strs[i][j]) {
                    ans = ans.slice(0, j)
                }
            }
        }
    }
    return ans
};
```
