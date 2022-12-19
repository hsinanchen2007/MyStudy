``` js
/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    //小于2的情况
    if (n < 2) {
        return n;
    }
    //如果大于2，就采用记忆化的方法
    //如果要记忆化，首先要有一个记忆化的容器
    let map = new Map();
    map.set(0, 0);
    map.set(1, 1);

    function memoize(number) {
        if (map.get(number) !== undefined) return map.get(number);

        let val = memoize(number - 1) + memoize(number - 2);
        //这一步是核心中的核心，将计算的结果缓存到map中
        map.set(number, val%1000000007);
        return val%1000000007;
    }
    return memoize(n)

};

```