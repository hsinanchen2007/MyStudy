### 解题思路

利用对象的结果,已存在的字符作为key,若对象中已经存在某个key,则返回false. 若直到遍历结束也没有返回false,则返回true.

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    let obj = {}
    for(let i of astr) {
        if(obj[i]) {
            return false
        }
        obj[i] = 1;
    }
    return true
};
```