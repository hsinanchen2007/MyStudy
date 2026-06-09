解题思路：
    1. 当遇到前后不等时 count 就是该字符的长度。
    2. 按照题意 count 超过两位数例如: 12个a会变为['a', '1', '2']; 112个b会变成['b', '1', '1', '2']，所以 String(count).length + 1 为变换之后的长度，原本长度就是 count，差值 dur 为新数组与老数组的长度差。
    3. 利用 splice 替换原数组
    4. 如果 chars 长度有变化即 dur 不为 0，指针 i 需要回位。

```js
/**
 * @param {character[]} chars
 * @return {number}
 */
var compress = function (chars) {
    let count = 1; // 每个字符的计数器
    for (let i = 0; i < chars.length; i++) {
        let dur = 0; // chars 改变之后长度变化值
        if (chars[i] !== chars[i + 1]) {
            if (count > 1) {
                dur = count - (String(count).length + 1);
                chars.splice(i + 1 - count, count, chars[i], ...String(count).split(''))]; // 替换原数组
                // 也可以下面这样错一位替换
                // chars.splice(i + 2 - count, count - 1, ...String(count).split(''));
            }
            count = 1;
            i = i - dur; // 数组长度变化，i 需要回位
            continue;
        }
        count += 1;
    }

    return chars.length;
};
```