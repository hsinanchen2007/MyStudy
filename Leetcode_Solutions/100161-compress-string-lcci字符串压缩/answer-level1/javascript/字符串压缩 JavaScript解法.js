### 解题思路
迭代S,如果当前字符与下一个字符不相等，在表示当前字符可压缩为当前字符加它出现的字数(`${S[i]}${count}`),压缩之后记录出现次数的count变量要重置为0.

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let count = 0;
    let result = '';
    for (let i = 0; i < S.length; i++) {
        count += 1;
        if (S[i] !== S[i + 1]) {
            result += `${S[i]}${count}`;
            count = 0;
        }
    }
    return result.length >= S.length ? S : result;
};
```