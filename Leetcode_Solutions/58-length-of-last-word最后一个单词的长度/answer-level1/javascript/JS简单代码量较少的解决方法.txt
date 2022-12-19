### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) { 
    let a =s.split(" ");
    let b = a.filter(item=>item);
    return b.length?b[b.length-1].length:0;
};
```把字符串用 “ ”转成数组，再用filter进行非空筛选，最后判断新数组是否有长度，有就输出最后一位单词的长度，没有就是为0；
