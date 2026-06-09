### 解题思路
此处撰写解题思路
分割字符串，然后反转内部每个字符串后连接
### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(/\s+/).map((item)=>(item.split('').reverse().join(''))).join(' ');
};
```