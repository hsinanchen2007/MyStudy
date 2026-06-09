### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} a
 * @return {number[]}
 */
var constructArr = function (a) {
    // 先乘这个数的左边，在成这个数的右边，最后相成，避免掉当前数
    let n = a.length;
    let b = [];
    // p代表前i个a[i]的乘积
    for (let i = 0, p = 1; i < n; i++) {
        b[i] = p;
        p *= a[i];
    }
    // p代表后i个a[i]的乘积
    for (let i = n - 1, p = 1; ~i; i--) {
        b[i] *= p;
        p *= a[i];
    }
    return b;
};  
```