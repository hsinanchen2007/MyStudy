### 解题思路
每次n = n & (n-1)运算可以消除n中最后一个1，因此统计执行了多少次即可得出1的个数。

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let sum = 0;
    while(n){
        n = n & (n-1);
        sum++;
    }
    return sum;
};
```