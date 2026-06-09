### 解题思路
replace

### 代码

```javascript
/**
 * @param {string} address
 * @return {string}
 */
const defangIPaddr = address => address.replace(/\./g, '[.]')
```