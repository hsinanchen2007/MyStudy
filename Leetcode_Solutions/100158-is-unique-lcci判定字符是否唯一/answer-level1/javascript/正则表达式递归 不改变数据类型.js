### 解题思路
根据正则循环递归第一个和剩余字符串对比

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    while(Boolean(astr.length)) {
        let length = astr.length==1?1:astr.length-1
        let source = astr.slice(0,1)
        let origin = astr.slice(1,astr.length)
        let reg = new RegExp(`${source}`, 'g')
        if (reg.test(origin)) {
            return false
        } else {
            return isUnique(origin)
        }
    }
    return true
};
```