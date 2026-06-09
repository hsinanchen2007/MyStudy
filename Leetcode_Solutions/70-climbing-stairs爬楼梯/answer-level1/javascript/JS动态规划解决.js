### 解题思路
    
1. 状态 最后一步走完后 共上了 n 节
    倒数第二步 可以是 直接走了两步 n-2 或者 走了一步 n-1
2. 转移方程
    num(n) = num(n-2) + num(n-1)
3. 边界值和初始值
    num(0) = 1 呆着不动
    num(-1) = 0, num (-2) = 0 ,num [1]= 1 
4. 顺序 从小到大
     

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    /**
     * 1.状态 最后一步走完后 共上了 n 节
     *        倒数第二步 可以是 直接走了两步 n-2 或者 走了一步 n-1
     * 2.转移方程
     *        num(n) = num(n-2) + num(n-1)
     * 3.边界值和初始值
     *      num(0) = 1 呆着不动
     *      num(-1) = 0, num (-2) = 0 ,num [1]= 1 
     * 4.顺序 从小到大
     */
    let numOfWay = [];
    numOfWay[0] = 1, numOfWay[1] = 1, numOfWay[2] = 2; 
    for(let i = 3; i<=n; i++){
        numOfWay[i] = numOfWay[i-1] + numOfWay[i-2]
    }
    return numOfWay[n];
};
```