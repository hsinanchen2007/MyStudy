### 解题思路
正则匹配最后一位，递归

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */

var reverse = function(x,num='') {
    var str = /(-?)(\d*)(\d)$/.exec(x);
    num = num+str[1]+str[3];
    if(str[2].length) {
        num = reverse(str[2],num);
    }
    num = Number(num);
    if(Math.abs(num)>(2**31)){
        num = 0;
    }
  return num;
};

```