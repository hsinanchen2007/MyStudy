### 解题思路
每一步js都提供了现成方法，直接使用即可。
trim()：去除字符串的头尾空格；
split(/\s+/)：以空格作为分割元素生成字符串数组；
reverse()：颠倒数组顺序；
join(' ')：以空格作为分隔符把数组元素放入一个字符串中。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.trim().split(/\s+/).reverse().join(' ')
};
```