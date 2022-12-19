
### 代码

```javascript
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
  var hammingDistance = function(x, y) {
    let r = (x ^ y).toString(2).match(/1/g);
    return r ? r.length : 0
  };

```