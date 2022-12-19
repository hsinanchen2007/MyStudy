### 解题思路
![image.png](https://pic.leetcode-cn.com/f4a1e5832847b44a2bf40828e6cc622c4ebfde1e302991a753f13cf9bdfb9a56-image.png)

代码简单，一看就懂

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    let reg = /^[\+\-]?\d+/;
    let result = reg.exec(str.trim());//trim()去掉str首尾空格
    if(result == null) return 0;//未匹配到
    return Math.max(Math.min(result[0], 2**31 - 1), -(2**31));
};
```