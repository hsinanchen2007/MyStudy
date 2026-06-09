### 解题思路
利用set去重，再比较去重后的数组长度

### 代码

```javascript
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    var arr = astr.split("");
    var arr1 = Array.from(new Set(arr));
    if(arr.length!=arr1.length){
        return false
    }else{
        return true
    }
};
```