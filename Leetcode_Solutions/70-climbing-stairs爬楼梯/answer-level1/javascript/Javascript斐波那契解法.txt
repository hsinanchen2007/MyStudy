### 解题思路

本质就是斐波那契数列。

**已知n为1时，f(1)是1；n为2时，f(2)是2。**
现在分析：n等于3时，迈出第一步只有两种选择，走1步或走2步：
- 当选择走1步时，则剩下的情况就是当n为3-1=2时的f(2)
- 当选择走2步时，则剩下的情况就是n为3-2=1时的f(1)
- 两种情况相加，即为当前解：f(3) = f(2) + f(1)；

> 可以推出，当n>2时,都满足f(n) = f(n-1) + f(n-2);

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) { 
    if(n===1) return 1;
    if(n===2) return 2;
    let result = 0;
    if(n>2){
       let f1 =1,f2=2;
       for(let i=2;i<n;i++){
           let tmp = f1+f2;
           f1 = f2;
           f2 = tmp;           
       }
       return f2;
    } 
};
```

**这种写法更好理解，但是递归性能差，会超时**
```javascript
var climbStairs = function(n) { 
    if(n===1) return 1;
    if(n===2) return 2;
    if(n>2){
        return (climbStairs(n-1)+climbStairs(n-2));
    } 
};
```