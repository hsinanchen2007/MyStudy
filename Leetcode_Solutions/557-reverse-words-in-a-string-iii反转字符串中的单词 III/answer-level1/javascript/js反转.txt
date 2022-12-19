### 解题思路
根据JS的控制反转,先将字符串分割成字符数组后反转再拼成反转后的字符串，但是此时的字符串是整个字符串反转，问题是原输入的每个单词反转，此时只需要把字符串单词根据空格分割数组再反转就得到结果。

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
   return s.split("").reverse().join('').split(" ").reverse().join(" ")
};
```