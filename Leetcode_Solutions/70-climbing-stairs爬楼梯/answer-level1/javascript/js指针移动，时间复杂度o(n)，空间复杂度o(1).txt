### 解题思路
指针移动，时间复杂度o(n)，空间复杂度o(1)

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n<=0)return 0
    if(n==1||n==2){
        return n
    }
    let a=1
    let b=2
    let c=0
    for(let i=3;i<=n;i++){
        c=a+b
        a=b //b给到a
        b=c //c给到b
    }
    return c

};
```