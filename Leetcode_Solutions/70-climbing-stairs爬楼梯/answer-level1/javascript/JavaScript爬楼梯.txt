思路：
1级：1 -> 1
2级：1+1,2 ->2
3级：从2级台阶跨1步，从1级台阶跨2步->1+2=3
4级：从3级台阶跨1步，从2级台阶跨2步->3+2=5
n级：从n-1级台阶跨1步，从n-2级台阶跨2步
**斐波那契数列**

方法一（会溢出）：
```
var climbStairs = function(n) {
    if (n <= 3) {
        return n;
    }
    return climbStairs(n -1) + climbStairs(n - 2);
};
```
方法二：
```
var climbStairs = function(n) {
    let array = [];
    array[1] = 1;
    array[2] = 2;
    for (let i = 3; i < n + 1; i++) {
        array[i] = array[i-1] + array[i-2];
    }
    return array[n];
};
```

