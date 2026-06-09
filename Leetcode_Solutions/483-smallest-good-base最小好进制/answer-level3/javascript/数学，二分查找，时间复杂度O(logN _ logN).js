// 考验数学功底的一道题😺。
// ![最小好进制数学解法.jpg](https://pic.leetcode-cn.com/7fee9a478e3bdf2d399c6aaa41d793e9c2689d0adac9d251ee34757c8d118975-%E6%9C%80%E5%B0%8F%E5%A5%BD%E8%BF%9B%E5%88%B6%E6%95%B0%E5%AD%A6%E8%A7%A3%E6%B3%95.jpg)
// 代码如下
// ```javascript
/**
 * @param {string} n
 * @return {string}
 */
var smallestGoodBase = function(n) {
    n = BigInt(n);
    //先确定 a 的最大值，因为Math.log2的参数不能是 BigInt，所以只能从小到大去算a的 i 次方
    let a_max;
    for(let i = 1; ; i++) {
        if(Math.pow(2, i) > n) {
            a_max = BigInt(i) + 1n;
            break;
        }
    }
    console.log("a_max:" + a_max);
    //a 不能等于 1，因为 a 等于 1 的时候，k 就等于 n 了。但是任意给定一个 n，都可以存在k 等于 n-1，a 等于 2，使得题目成立
    for(let a = a_max; a >= 2n; a--) {
        //k >= 2 && k <= n - 1, 可以使用二分查找的方式
        let start = 2n;
        let end = n - 1n;
        let k;
        while(true) {
            k = (start + end) / 2n;
            let result = (k ** a - 1n) / (k - 1n);
            if(result === n) return k.toString();
            else if(result > n) {
                end = k - 1n;
            } else if(result < n) {
                start = k + 1n;
            }
            if(start > end) break;
        }
    }
};
// ```
// 因为a_max <= logN，所以外层循环logN次，内层循环是用二分法寻找 2 到 N 之间的数字，也是 logN次，总的时间复杂度是O(logN * logN)， 总的空间复杂度是 O(1)。