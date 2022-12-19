1.看到和个数相关的题目，我是想到了hash表
2.在数组和对象之间，我选择了用数组存放，效率应该要高点
3.字符串的题目考虑转为数组，也是个常见的思路

$。和本题相关的思路：1.偶数可以全部作为回文
                  2.奇数回文数=个数-1；
                  3.等于1的，或者已经出现的奇数，一共只能提供一个回文数。
所以，增加一个标记为，虽然可能因此增加了时间消耗。
```
var longestPalindrome = function (s) {
    if (s.length === 0) return s;
    s = s.split("");
    let snum = new Array(64).fill(0);//比26多，因为，A是65 a是97
    let res = 0;
    let jishu1 = 0;//增加的标志位
    s.filter(element => {
        snum[(element.charCodeAt() - 65)]++;
    });
    for (let i = 0; i < snum.length; i++) {
        if (snum[i] > 0 && snum[i] % 2 === 0) res += snum[i];
        else if (snum[i] > 0 && snum[i] % 2 === 1) {
            jishu1 = 1;
            res = res + snum[i] - 1;
        }
    }
    return res += jishu1;
};
```
