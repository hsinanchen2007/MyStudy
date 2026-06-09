### 解题思路
- 先去空格，再用空格split成数组，最后一个单词的长度就出来了

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const str = s.trim()
    const array = str.split(' ')
    const length = array.length
    return array[length - 1].length
};
```