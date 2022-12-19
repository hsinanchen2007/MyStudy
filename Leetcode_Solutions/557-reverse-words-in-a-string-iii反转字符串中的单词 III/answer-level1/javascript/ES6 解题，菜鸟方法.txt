### 解题思路
split(' ')字符串按空格进行分割为数组，数组的先后顺序就是单词的先后顺序
map()对数组进行遍历，然后对每个元素反转 拼接

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(item =>
       item.split('').reverse().join('')
    ).join(' ')
};
```