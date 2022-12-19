### 解题思路


### 代码

```javascript
/**
 * @param {string} address
 * @return {string}
 */
var defangIPaddr = function (address) {
    return address.replace(/\./g, '[.]')
};
```