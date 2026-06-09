#### 思路
从后往前遍历字符串，如果左边的数比右边的数小，做减法，否则做加法。
#### 代码
```
var romanToInt = function(s) {
    // 保存映射关系
    let digits = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000,
    };
    // 先将最左边数字保存
    let sum = digits[s[s.length - 1]];
    for (let i = s.length - 2; i >= 0; i--) {
        // 左边大，加
        if (digits[s[i]] >= digits[s[i+1]]) {
            sum += digits[s[i]];
        } else { // 左边小，减
            sum -= digits[s[i]];
        }
    }
    return sum;
};
```
