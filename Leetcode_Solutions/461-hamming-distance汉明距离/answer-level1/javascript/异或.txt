### 解题思路
方法一：异或，for循环统计

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function(x, y) {
    var num = x ^ y;
    var count=0;
    var str=parseInt(num).toString(2);
    for(var i=0;i<str.length;i++){
        if(str[i]=='1'){
            count++;
        }
    }
    return count;
};
```
方法二：split函数统计
```
var hammingDistance = function(x, y) {
    var num = x ^ y;
    var str=parseInt(num).toString(2);
    return str.split('1').length-1;
};
```
