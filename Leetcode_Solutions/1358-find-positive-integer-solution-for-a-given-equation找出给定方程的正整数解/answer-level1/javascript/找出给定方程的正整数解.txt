本题有两种解法。

- 两次循环
题目读懂之后就很简单了。
第一个入参是函数，第二个是预期的结果。然后求有多少解。
简单说就是暴力解二元方程。解的范围确定，而且是整数，同时函数是单调递增的。
两个for循环解决。
```
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 *
 * };
 */
/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
var findSolution = function(customfunction, z) {
    let res = [];
    for (let x = 1; x <= 1000; x++) {
        for (let y = 1; y <= 1000; y++) {
            // 如果customfunction.f(x, y) > z，根据题意 customfunction.f(x, y + 1) 肯定也比 z 大
            if (customfunction.f(x, y) > z) {
                break;
            }
            // 相等的话，那么是其中一个解
            else if (customfunction.f(x, y) === z) {
                let ans = [x, y];
                res.push(ans);
            }
        }
    }
    return res;
};
```
时间复杂度：$O(n^2)$

- 双指针
再仔细想一下好像不需要这么多次的循环。
根据函数是单调递增的特性，双指针的解法就出来了。
x从1开始增，y从1000开始减。
```
/**
 * // This is the CustomFunction's API interface.
 * // You should not implement it, or speculate about its implementation
 * function CustomFunction() {
 *
 *     @param {integer, integer} x, y
 *     @return {integer}
 *     this.f = function(x, y) {
 *         ...
 *     };
 *
 * };
 */
/**
 * @param {CustomFunction} customfunction
 * @param {integer} z
 * @return {integer[][]}
 */
var findSolution = function(customfunction, z) {
    let res = [];
    let x = 1;
    let y = 1000;
    while(x > 0 && x <= 1000 && y > 0 && y <= 1000) {
        if (customfunction.f(x, y) === z) {
            let ans = [x, y];
            res.push(ans);
            x++;
        }
        else if (customfunction.f(x, y) > z) {
            y--;
        }
        else {
            x++;
        }
    }
    return res;
};
```
时间复杂度：$O(n)$