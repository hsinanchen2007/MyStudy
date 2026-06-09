### 解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let s = 0;
    let m = Math.pow(2, 31);
    while(x!=0) {
        s = s*10 + x%10;
        x = parseInt(x/10);
    }
    return (s>m-1||s<-m)? 0 : s;
};
```