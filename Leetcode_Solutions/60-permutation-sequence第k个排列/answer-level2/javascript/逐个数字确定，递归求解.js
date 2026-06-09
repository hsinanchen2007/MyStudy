```
/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    /*以每个数字开头组成的数的数目都是相等的，求出来以每个数开头的数有多少，缩写寻找范围，递归求解*/
    let res = [];
    const map = new Map();     // 用来存储阶乘的值
    let init = [];
    let i = 1;
    map.set(1, 1);
    while (i <= n) {
        init.push(i++);
        map.set(i, map.get(i - 1) * i);
    }
    const getNum = function (arr, l) {
        if (l <= 1) {                    /*求第一小的数，直接返回即可*/
            res = res.concat(arr);
            return;
        }
        let len = arr.length;
        let num = map.get(len - 1);          // 求len - 1位数能有多少种组合，从而确认当前应该以哪个数为开头
        let start = Math.ceil(l / num);    /*此时就是索引为start的值是当前遍历中的第一位数*/
        l = l - num * (start - 1);
        start = arr[start - 1];
        res.push(start);
        arr.splice(arr.indexOf(start), 1);
        getNum (arr, l);
    };
    getNum(init, k);
    return res.join("");
};
```
