### 解题思路
等差即 A[i-1]-A[i] == dis, 计算等差长度n，就知道等差子素组数为n*(n+1)/2;
所以只需要找到有多少种差值，及每种等差的长度。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var numberOfArithmeticSlices = function(A) {
    if (A.length < 3) {
        return 0;
    }
    var l = A.length;
    var dLength = 0;
    var count = 0
    var dis = null;
    for (var i = 1; i < l; i++) {
        var a = A[i - 1],
            b = A[i]
        if (b - a == dis) {
            dLength++
        } else {
            dis = b - a;
            count += dLength * (dLength + 1) / 2
            dLength = 0;
        }
    }
    count += dLength * (dLength + 1) / 2
    return count;
};
```