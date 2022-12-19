### 解题思路
trim 去除两边的space
split后的最后一个字符串长度

### 代码

```javascript
/**
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。

如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let list = s.trim().split(' ');
    return list[list.length - 1].length;
};
```