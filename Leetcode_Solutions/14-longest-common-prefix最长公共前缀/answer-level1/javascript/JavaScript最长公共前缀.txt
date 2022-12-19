#### 思路
1. 遍历数组第一个字符串`strs[0]`；
2. 将第`i`个字符和数组中剩余字符串的相同位置字符进行比较；
3. 如果相同，`i++`；如果不同，返回`strs[0]`中前`i`个字符组成的字符串即可。
#### 代码
```
var longestCommonPrefix = function(strs) {
    // 处理特殊情况
    if (strs.length === 0) {
        return "";
    }
    if (strs.length === 1) {
        return strs[0];
    }
    let i = 0;
    for (; i < strs[0].length; i++) {
        const char = strs[0][i];
        let j = 1;
        // 剩余字符串的相同位置字符进行比较
        while (j < strs.length) {
            if (strs[j][i] === char) {
                j++;
            } else {
                // 一旦不相同就返回
                return strs[0].substring(0, i);;
            }
        }
    }
    // 如果比较完了，strs[0]就是所求最长公共前缀
    return strs[0];
};
```
