### 解题思路
如题

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    const prefixArr = [];
    const firstItem = strs.shift();
    for (let idx in firstItem){
        let char = firstItem[idx];
        if (!strs.every((item) => item[idx] === char)){
            break;
        }
        prefixArr.push(char);
    }
    return prefixArr.join('');
};
```