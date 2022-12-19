### 解题思路

- 如果 ``s`` 为空或者只有空格，那么返回 ``''``
- 否则反转 ``字符串`` 里的单词

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    if (!s || !s.trim()) {
        return ''
    }
    return s.match(/\S+/g).reverse().join(' ')
};
```