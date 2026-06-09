### 解题思路
用for循环字符串，用includes向当前元素之后查询是否有重复元素，做出判断。

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    for(let i=0;i<astr.length-1;i++){
        if(astr.includes(astr[i],i+1)){
            return false
        }
    }
    return true
};
```