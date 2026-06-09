### 解题思路
找规律递推...

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var countOrders = function(n) {
    let mod = 1e9 + 7
    let last=1;
    for(let i=1;i<=n;i++){
        //组合 C(2,2*i)
        let c=i*(2*i-1);
        last=(last*c) % mod;
    }
    return last;

};
```