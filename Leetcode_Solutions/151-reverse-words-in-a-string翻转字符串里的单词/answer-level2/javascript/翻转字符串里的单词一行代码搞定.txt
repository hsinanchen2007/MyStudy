### 解题思路
此处撰写解题思路
将字符串进行切割，筛选，翻转拼接，一行代码即可

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').filter(i => i!= '').reverse().join(' ')
};
```