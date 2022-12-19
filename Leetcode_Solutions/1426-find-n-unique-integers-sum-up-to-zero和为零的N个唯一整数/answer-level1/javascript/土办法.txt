### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var sumZero = function (n) {
    let ans = [];
    let len = n >> 1;
    n % 2 !== 0 && ans.push(0);
    while (len) {
        ans.push(len, -len);
        len--;
    }
    return ans;
};
```