### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    // 要先去除最后字符是空格的情况
    // trim()方法去除字符串头尾的空格，不改变原数组值
    s = s.trim();
    let arr = s.split(' ');
    let len = arr.length;
    // 特判，不存在最后一个单词
    if(len == 0) return 0; 
    return arr[len - 1].length;
};
```