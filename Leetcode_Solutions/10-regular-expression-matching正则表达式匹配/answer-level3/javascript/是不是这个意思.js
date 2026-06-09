### 解题思路
在下是个粗人看不太懂代码

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
   return new RegExp('^'+p+'$').test(s);
};
```