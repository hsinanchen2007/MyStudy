## 思路

括号匹配类型的问题，很适合用栈来解决

从前往后遍历，遇到 `\[0-9]\` ，判定为乘数，需要兼容多位数的场景，进行累加

遇到 `[` 结束乘数的位数累加，并将`乘数`转换为 number 类型并放进栈中

遇到字母直接入栈

遇到 `]` 时，while 循环从栈中取值，直到取出的值类型为 number 类型，此时取到的`temp`为最小单位 `[...]` ，curr 为 `[..]` 之前的乘数

将重复之后的字符串推进栈中，继续往后遍历

...

```
/*
 * @lc app=leetcode.cn id=394 lang=javascript
 *
 * [394] 字符串解码
 */
/**
 * @param {string} s
 * @return {string}
 */

var decodeString = function (s) {
    let stack = []; // 保存需要 repeat 的字符串
    let times = ''; // 乘以的倍数

    for (let i = 0, len = s.length; i < len; i++) {
        let item = s[i];

        if (/[0-9]/.test(item)) {
            if (i === 0 || /[0-9]/.test(s[i - 1])) {
                times += item;
            } else {
                times = item
            }
        } else if (item === '[') {
            times && stack.push(Number(times));
            times = '';
        } else if (item === ']') {
            var curr = stack.pop();
            var temp = '';
            while (typeof curr !== 'number') {
                temp = curr + temp;
                curr = stack.pop();
            }
            temp = temp.repeat(curr);
            stack.push(temp);
        } else {
            stack.push(item);
        }
    }
    return stack.join('');
};


```
