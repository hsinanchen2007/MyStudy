### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    path = path.split(/\/+/);
    const stack = [];
    for (let dir of path) {
        if (dir === '..') {
            stack.pop();
        } else if (dir && dir!=='.') {
            stack.push(dir);
        }
    }
    return `/${stack.join('/')}`;
};
```