### 解题思路
![image.png](https://pic.leetcode-cn.com/a1db06984c924196561cfa51a1fd2dc163153cb9446a5a73749e42e777a57861-image.png)

- 通过 JS 中的 test（）全局匹配

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function(n) {
    let res = n.toString(2)
    let patt = /00|11/g
    return !patt.test(res)
    }
```