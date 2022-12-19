### 解题思路
约瑟夫环
f(n,m)= ( f(n-1,m) % n + m) % n;



### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    let f=0;
    //f[1]=0;
    let i=2;
    while(i<=n){
        f=(f+m) % i;
        i++;
    }
    return f;
};
```