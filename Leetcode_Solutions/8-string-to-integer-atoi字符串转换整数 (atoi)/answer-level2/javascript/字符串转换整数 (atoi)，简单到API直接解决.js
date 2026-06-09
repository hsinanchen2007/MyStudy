### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} str
 * @return {number}
 */
// 直接调API解决；另外注意的就是32位有效位的处理
var myAtoi = function(str) {
    const res = parseInt(str, 10);
    if (isNaN(res)) {
        return 0
    }
    if (res > 2147483647) { // Number.MAX_SAFE_INTEGER > 2147483647, 无解，因为js最大数比他给定的大
        return 2147483647;
    }
    if (res < -2147483648) { //  Number.MIN_SAFE_INTEGER
        return -2147483648;
    }
    return res;
};
```