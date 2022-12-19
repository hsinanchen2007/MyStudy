### 解题思路
无限与上一位作比较
相同则加当前字符串，不同则累加记数数字
等待下次不同时加累加的数字，恢复计数初始值，等待下次累加
最后一位则直接加计数当前值（1或者其他）

#### 注意审题，有坑！！！

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    // 切成数组形式
    let splstr = S.split('')
    // 计数
    let count = 1
    // 返回的数据
    let restr = ''
    // 遍历
    splstr.forEach((item, index) => {
    // 当前与后一位比较
    if (item == splstr[index - 1]) {
        count++ // 如果相等则开始计数
    } else {
        if (index > 0) { // 排除第0位
        restr += count // 不相等之后累加计数得出的数字
        count = 1 // 恢复计数初始值
        }
        restr += item // 不相等则累加
    }
    if (index + 1 === S.length) {
        restr += count
    } // 若是最后一位，直接累加计数
    });
    return S.length <= restr.length ? S : restr
};
```