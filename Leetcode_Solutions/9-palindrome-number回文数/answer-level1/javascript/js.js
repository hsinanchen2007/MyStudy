### 解题思路
![屏幕快照 2019-12-13 上午10.24.12.png](https://pic.leetcode-cn.com/1868702270d5ac3128c785750d4a61fa71916aaf7d65dabbe41740096d442c0d-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-13%20%E4%B8%8A%E5%8D%8810.24.12.png)


### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false
    let a = 0, init = x
    while(x > 9) {
        a = a*10 + x%10*10
        x = parseInt(x/10)
    }
    let res = a + x
    return res === init
};
```
