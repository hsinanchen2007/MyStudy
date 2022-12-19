### 解题思路
此处撰写解题思路
字符串拆分成数组 然后每个元素执行倒序操作
### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    return s.split(' ').map(item=>
         item = item.split('').reverse().join('')
    ).join(' ').toString()
};
```