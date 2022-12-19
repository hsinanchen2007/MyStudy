### 解题思路
将字符串排序后用hash记录

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var obj={};
    var result = [];
    for(let i =0;i<strs.length;i++){
        let s = Array.from(strs[i]).sort().join('');
        Array.isArray(obj[s])?obj[s].push(strs[i]):obj[s]=[strs[i]];
    }
    for(key in obj){
        result.push(obj[key]);
    }
    return result;
};
```