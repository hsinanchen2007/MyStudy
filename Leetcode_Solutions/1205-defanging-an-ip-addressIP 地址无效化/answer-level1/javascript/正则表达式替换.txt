### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function(address) {
    let reg = /\./g
    return address.replace(reg,'[.]')
};
```