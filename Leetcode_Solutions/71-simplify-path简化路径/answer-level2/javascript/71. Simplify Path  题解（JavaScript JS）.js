### 思路
将`path`以`'/'`分割成数组，如 `/a/./b/../../c/`分割成`[ '', 'a', '.', 'b', '..', '..', 'c', '' ]`。 新建一个栈`stack`为当前的路径，遍历`path`分割后的数组元素:
<br>

 * 遇到正常的字母时，推入 `stack` 中
 * 遇到 `..` 时，`stack` 弹出最近一个路径
 * 遇到 `.` 或者为空时，不修改当前 stack。
 * 最后返回 `'/' + stack.join('/')` 为新的路径

### 题解

```javascript []
var simplifyPath = function(path) {
    const stack = [];
    const pathArr = path.split('/');
    
    for (let item of pathArr) {
        if (item === '' || item === '.') {
            continue;
        } else if (item === '..') {
            stack.pop();
        } else {
            stack.push(item);
        }
    }

    return '/' + stack.join('/');
};
```