### 解题思路
编写字典，查询字典，累加

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
const DOUBLE_DICT = {
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900
};
const DICT = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
};

var romanToInt = function (s) {
    let p = 0,          // 指针
        result = 0;     // 结果

    // 循环
    while (p < s.length) {
        // 先取出指针后两个字符，判断是否为组合字符
        let target = s.substr(p, 2);
        if (DOUBLE_DICT[target]) {
            result += DOUBLE_DICT[target];
            p += 2;
        } else {
            // 不是，则当作普通单字符执行
            result += DICT[target[0]];
            p++;
        }
    }

    return result;
};
```