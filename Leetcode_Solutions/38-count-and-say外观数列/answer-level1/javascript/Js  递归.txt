```
/**
 * @param {number} n
 * @return {string}
 * 递归实现，因为每一个值都是依据上一个值给出的。
 */
var countAndSay = function(n) {
    if (n === 1)
        return '1';
    if (n === 2)
        return '11';
    if (n === 3)
        return '21';
    let pre = countAndSay(n - 1);
    let res = '', count = 1;
    for (let i = 0; i < pre.length; i++){
        if (pre[i + 1] && pre[i + 1] === pre[i]) {
            count ++;
        } else {
            res += count + pre[i];
            count = 1;
        }
    }
    return res;
};
```