### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} N
 * @return {number}
 */
var fib = function(N) {
    let l=0, r=1;
    while(N-->0){
        [l, r] = [r, l+r];
    }
    return l;
};
```