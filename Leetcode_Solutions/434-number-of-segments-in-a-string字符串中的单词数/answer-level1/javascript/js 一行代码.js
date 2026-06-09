### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function(s) {
    return !s.trim() ? 0 : s.trim().split(' ').filter(Boolean).length
};
```