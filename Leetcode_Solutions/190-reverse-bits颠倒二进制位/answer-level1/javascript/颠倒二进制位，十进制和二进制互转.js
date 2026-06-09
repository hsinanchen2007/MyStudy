### 解题思路
toString(2)转换成二进制
padStart(32,0) 以0补全32位
parseInt(s,2) 二进制转十进制

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    var str = n.toString(2).padStart(32,0).split('')
    //reserve().join('')
    var s = ''
    for(let i = str.length-1;i>=0;i--){
        s += str[i]
    }
    return parseInt(s,2)
};
```