### 解题思路
此处撰写解题思路使用正则去掉字符串前后的空字符，然后使用split方法拆分数组，看数组是否为空，为空的返回0，不为空返回 最后一项的length

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
     const srtArr = s.replace(/(^ +| +$)/g, '').split(' ');
     return srtArr.lenght?srtArr[srtArr.length - 1].length:0;
};
```