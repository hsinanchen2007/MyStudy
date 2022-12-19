### 解题思路
只统计数量 那么出现次数为偶数的数量加2 奇数的全局只统计一次

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const sArray = s.split('');
    const temp = {};
    let count = 0;
    sArray.forEach(item => {
        if (temp[item]) {
            count += 2;
            temp[item] = undefined;
        } else {
            temp[item] = 1;
        }
    })
    const keys = Object.keys(temp);
    if (keys.some(key => temp[key] === 1)) {
        count += 1;
    }
    return count;
};
```