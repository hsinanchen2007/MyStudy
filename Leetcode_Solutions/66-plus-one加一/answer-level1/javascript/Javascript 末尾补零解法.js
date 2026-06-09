思路：根据题意加一，因为它是只加一，所以加完结果只有两种可能
1、等于10
2、小于10

第一种情况需要进1，当前位数值为0，往上继续加直到相加结果小于10（需要处理特殊情况99，999）
第二种情况直接返回当前结果即可

代码实现
```
var plusOne = function (digits) {
    // 末尾补0
    digits[digits.length] = 0;
    for (let i = digits.length - 2; i >= 0; i--) {
        digits[i]++;
        digits[i] = digits[i] % 10;
        if (digits[i] !== 0) {
            // 第二种情况，相加结果小于10
            digits.length = digits.length-1;
            return digits;
        }
        // 第一种情况继续加，循环继续
    }
    // 特殊情况，所有位数都为9；
    digits[0] =1;
    return digits;
};
```
