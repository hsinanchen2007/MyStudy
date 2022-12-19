## 第一种解法
这道题最开始是用最基础的方法做的，就是双层循环 外层循环1-n 内层循环2-sqrt(n)判断是否质数

```
var countPrimes = function (n) {
    let ret = 0,
        flag = 1;
    if (n < 2) {
        return 0
    }
    for (let i = 1; i < n; i++) {
        for (let j = 2; j <= Math.sqrt(i); j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 2) {
            ret++;
        } else {
            flag = 2;
        }
    }
    return ret
};
```

## 第二种解法

采用厄拉多塞筛法

介绍：改算法在寻找素数时，采用了一种与众不同的方法：先将 2－N 的各数放入表中，然后在 2 的上面画一个圆圈，然后划去 2 的其他倍数；第一个既未画圈又没有被划去的数是 3，将它画圈，再划去 3 的其他倍数；现在既未画圈又没有被划去的第一个数是 5，将它画圈，并划去5的其他倍数……依次类推，一直到所有小于或等于N的各数都画了圈或划去为止。

这时，表中画了圈的以及未划去的那些数正好就是小于 N 的素数。

主要适用了ES6的两个数组方法
```
var countPrimes = function (n) {
    if (n <= 2) {
        return 0
    }
    // 生成一个0-n-1的数组
    let temp = [...new Array(n).keys()];
    temp[0] = temp[1] = null
    // console.log(temp)
    for (let i = 2; i < n; i++) {
        for (let j = 2; i * j <= n; j++) {
            temp[i * j] = null;
        }
    }
    //筛一下非null的值 filter是es6的一个数组方法，可以对数组进行一个筛选
    temp = temp.filter(function (a) {
        return a != null
    })
    // console.log(temp)
    return temp.length
}; 
```