### 解题思路
如果直接用 JS 内置的 (parseInt(a, 2) + parseInt(b, 2)).toString(2)，会因为数值超过表示范围而通不过某些测试用例。

因此：先用数组从最小位开始存储每一位数，再依次相加，记录进位并更新结果。

### 代码

```javascript
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
// var addBinary = function(a, b) {
//     return (parseInt(a, 2) + parseInt(b, 2)).toString(2);
// };
const genReverseArr = (a) => a.split("").reverse();

const max = (a, b) => (a > b ? a : b);

var addBinary = function(a, b) {
    const arrA = genReverseArr(a), arrB = genReverseArr(b);
    const maxLen = max(arrA.length, arrB.length);
    let currentIndex = 0, res = '', carry = 0;
    while (currentIndex < maxLen) {
        let temp = carry + (arrA[currentIndex] ? parseInt(arrA[currentIndex], 10) : 0) + (arrB[currentIndex] ? parseInt(arrB[currentIndex], 10) : 0);
        carry = temp > 1 ? 1 : 0;
        res = temp % 2 + res;
        ++currentIndex;
    }
    if (carry) {
        res = '1' + res;
    }
    return res;
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)