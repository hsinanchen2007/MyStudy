### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
    if(s.length === 0) return s;
    const strArray = s.split(' ');
    const result = strArray.join('%20');
    return result;
};
```