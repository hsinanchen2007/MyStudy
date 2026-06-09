### 解题思路
1. 最容易想到的方式是递归，但是耗时太久，失败，
2. 改用for循环， 注意n小于等于 2 的情况

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n <= 2){
        return n
    }

    var res1 = 1;
    var res2 = 2;
    var sum = res2;
    for(var i = 2;i < n;i ++){
        sum = res1 + res2;
        res1 = res2;
        res2 = sum;
    }
    return sum;
};
```