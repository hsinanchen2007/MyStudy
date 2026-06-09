### 解题思路
双重for循环最好理解，但就是耗时间

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length === 0){
        return '';
    }
     if(strs.length === 1){
        return strs[0];
    }
    var first = strs[0];
    var chart = '';
    for(var j = 0;j<first.length;j++){
        chart = first.charAt(j);
        for(var i = 1;i<strs.length;i++ ){
               if(strs[i].charAt(j) !== chart){
                 return j == 0? '': first.slice(0,j);
               }
            } 
        }
    return first
};
```