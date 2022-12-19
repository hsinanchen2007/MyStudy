### 解题思路
    三行代码解决所有问题

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
    p='^'+p+'$';
    var re=new RegExp(p);
    return re.test(s);
};
```