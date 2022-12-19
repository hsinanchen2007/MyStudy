### 解题思路
使用正则表达式匹配到符号和数字，再比较数字

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let arr=/^\s*(\+|\-)?(\d+)/.exec(str);
    if(!arr){
        return 0;
    }
    let result=(arr[1]?arr[1]:'')+arr[2];
    if(result>2**31-1){
         return (2**31)-1;
    }else if(result<-(2**31)){
        return -(2**31);
    }
    return result;
};
```