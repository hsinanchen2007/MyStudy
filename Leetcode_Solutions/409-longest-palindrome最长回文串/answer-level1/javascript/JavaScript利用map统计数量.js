### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    var sMap = new Map();
    var res = 0;
    var flag = false;
    for(var i = 0; i < s.length; i++){
        if(sMap.has(s[i])) sMap.set(s[i], sMap.get(s[i])+1);
        else sMap.set(s[i], 1);
    }
    sMap.forEach(function(value,key){
    　　if(value % 2 == 0) res += value;
        else {
            res += value-1;
            flag = true;
        }
    });
    return flag ? res+1 : res;
};
```