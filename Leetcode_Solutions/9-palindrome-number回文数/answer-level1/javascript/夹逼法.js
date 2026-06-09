### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(Object.prototype.toString.call(x) !== '[object Number]' || x < 0) return false
    x = x.toString()
    const len = x.length
    let left = 0
    let right = len - 1
    while(left < right) {
      if(x[left++] !== x[right--]) {
        return false
      }   
    }
    return true
};
```