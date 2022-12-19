### 解题思路
通过indexOf遍历查找当前字符第一次出现下标是否等于最后一次出现，如果不等于则表示重复返回false，默认返回true。

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    for(let i = 0;i<astr.length;i++){
        if(astr.indexOf(astr[i])!==astr.lastIndexOf(astr[i])){
            return false
        }
    }
    return true
};
```