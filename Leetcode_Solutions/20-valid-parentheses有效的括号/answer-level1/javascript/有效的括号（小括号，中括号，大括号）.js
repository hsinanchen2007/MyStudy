### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
// 为什么只有反括？
// 因为只有反括才有资格去做成对匹配
const valid = {
    ')': '(',
    '}': '{',
    ']': '[',
}

// 栈顶法解决，通过遍历到最后，栈顶最后是否有元素来解决；
var isValid = function(s) {
    const arr = s.split('');
    const length = arr.length;
    const res = [];
    let len = 0;
    for(let i = 0; i < length; i++) {
        const cur = arr[i];
        // 栈顶元素， 如果当前元素和栈顶元素能配对，那么就出栈，反之入。。。
        const now = res[len - 1];
        // len > 0 ，只要是防止开始使，now为undefined，导致 undefined === undefined
        if (len > 0 && now === valid[cur] ) {
            res.pop();
            len--;
        } else {
            res.push(cur);
            len++
        }
    }
    if (len === 0) {
        return true;
    }
    return false;
};
```