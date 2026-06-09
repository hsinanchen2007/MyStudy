22! 中，5的倍数的有Math.floor(22/5)=4个，分别是5 10 15 20。
```javascript
/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
    let count = 0;
    while(n>0) {
       // 学习其他大佬的思路，主要找出2*5的组合，每一个这样的组合就会产生一个0
       //，但是阶乘中2出现的次数通常大于或等于5出现的次数，
       // 比如8可以分解成2*2*2。5隔五个数出现一次
       const k =  Math.floor(n/5);
       count += k;
       // 更新n的值
       n = k;
    }
    return count;
};
```