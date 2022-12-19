### 思路

##### climbStairs(n)代表n级楼梯的总爬法数。 那么爬到最后一级(n级)楼梯前一步只有两种走法，把两种走法的总爬法数加起来即可，于是```climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)```。只要给定初始值n为1和n为2的情况即可；

解法：
```
var climbStairs = function(n) {
    if( n === 1) return 1;
    if( n === 2 ) return 2;
    return climbStairs(n-2) + climbStairs(n-1);
};
```

### 优化
##### 通过调试可知，上面代码会超时，因为性能太差。原因是climbStairs(n)会被重复计算多次，而且n越大，重复递归次数越多。我们可以用memory对象来储存climbStairs(n)的结果；

优化后解法：

```
let memory = {};
var climbStairs = function(n) {
    if( memory[n] ) return memory[n];
    if( n === 1) return memory[n] = 1;
    if( n === 2 ) return memory[n] = 2;
    return memory[n] = climbStairs(n-2) + climbStairs(n-1);
};
```