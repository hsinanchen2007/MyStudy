### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let res =0;
    while(n!==0) {
        res += n & 1;
        n>>>=1;
    }
   return res;
};
```