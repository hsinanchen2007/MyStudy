### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let t=32, c=0, m=1;
    while(t-->0){
        if(n&m)c++;
        m<<=1;
    }
    return c;
};
```