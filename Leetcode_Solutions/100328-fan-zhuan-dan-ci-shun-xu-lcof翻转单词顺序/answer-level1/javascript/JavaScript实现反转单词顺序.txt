### 解题思路
此处撰写解题思路
1.字符串格式化成数组，按空格分割
2.去掉空数组
3.反转数组
4.转换成字符串

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  return s.split(' ').filter((item) => item.length > 0).reverse().join(' ')
};
```