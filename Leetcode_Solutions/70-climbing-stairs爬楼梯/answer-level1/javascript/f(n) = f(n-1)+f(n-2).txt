### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n==1) return 1;
    if(n==2) return 2;
    var left = 1
    var right = 2
    var i = 2
    while(i<n){
        var now = left + right
        left = right
        right = now
        i++
    }
    return now
};
```