```javascript []
console.log('Hello world!')
```
//使用一个缓存对象保存计算中间值
var cache = {};

var climbStairs = function(n) {
    //非法输入
    if (n <= 0) {
        return -1;
    }
    //当爬1个台阶时,只有一种方法;
    //当爬2个台阶时,有两种方法,迈两步或迈一步
    if (n <= 2) {
        return n;
    }
    /*
    * 要爬到第n个台阶,可选的方法
    * 1.在n-1个方法迈一步
    * 2.在n-2个台阶上迈两步
    * */
    var prevStep, prevPrevStep;
    //递归计算爬n-1个台阶的方法,并利用缓存
    if (cache[n - 1] !== undefined) {
        prevStep = cache[n - 1];
    } else {
        prevStep = climbStairs(n - 1);
        cache[n - 1] = prevStep;
    }
    //递归计算爬n-2个台阶的方法,并利用缓存
    if (cache[n - 2] !== undefined) {
        prevPrevStep = cache[n - 2];
    } else {
        prevPrevStep = climbStairs(n - 2);
        cache[n - 2] = prevPrevStep;
    }
    //将这两种方法的可能性相加得到最终结果
    return prevStep + prevPrevStep;
};
```
