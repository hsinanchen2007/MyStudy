### 解题思路
此处撰写解题思路
将haystack 按照 needle 的长度，截取分配给 keyObj;
如果匹配就返回 index;最终如果都不匹配，就 -1;
### 代码

```javascript
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    var hLen = haystack.length;
    var nLen = needle.length;
if(needle === ""){
    return 0;
} else if(hLen < nLen){
    return -1;
} else {
    if(haystack.indexOf(needle[0]) === -1){
        return -1;
    } else {
        var keyObj = {};
        for(var i=0; i<hLen; i++){
            if(haystack[i] === needle[0]){
// 这个地方去截取 needle 长度的字符串，跟 needle 匹配
                keyObj[i] = haystack.substr(i,nLen);
                if(keyObj[i]===needle){
                    return i;
                }
            }
        }
        return -1;
    }
}
};
```