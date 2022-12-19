### 思路
从左到右查找：
- 设置游标变量 left，记录不含重复字符的子字符串在整个字符串中的起始位置，初始值为 0，一旦出现重复，就偏移到子字符串中那个重复字符位置的右侧。
- 设置子字符串变量 tem_str，保存循环中如果发现的不含重复字符的子字符串，初始值为 ''。
- 设置长度变量 max_len，记录不含重复字符的子字符串的最大长度值，初始值为 0。
- 以上变量均在循环中更新。

### 代码
```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    if (!s.length) {
        return 0
    }
    let left = 0
    let tem_str = ''
    let max_len = 0
    for (let i = 0; i < s.length; i++) {
        const ele = s[i]
        if (tem_str.includes(ele)) {
            left += (s.slice(left, i).indexOf(ele) + 1)
            continue
        }
        tem_str = s.slice(left, i + 1)
        max_len = Math.max(max_len, tem_str.length)
    }
    return max_len
};
```