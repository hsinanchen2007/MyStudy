### 解题思路
简单暴力的方法，用第一个字符串的字母依次去跟后面的比较。
注意控制标识，及时跳出循环

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    var s = '';
    if(strs.length) {
        for(var i = 0; i < strs[0].length; i++) {
            var flag = false;
            for(var k = 1; k < strs.length; k++) {
                if(strs[0][i] !== strs[k][i]) {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            s = s.concat(strs[0][i]);
        }
    }
    return s;
};
```