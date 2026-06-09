### 解题思路
额 写完之后看大家的，感觉开了作弊器。比10%的人慢 开了作弊器都这么丢人

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let min=-Math.pow(2,31);
    let max=Math.pow(2,31)-1;
    let res=parseInt(str)
    return isNaN(res)?0:(res<=max&&res>=min?res:(res<0?min:max))

};
```