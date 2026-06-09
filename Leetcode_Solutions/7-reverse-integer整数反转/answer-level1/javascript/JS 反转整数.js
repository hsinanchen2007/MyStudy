## 解题思路
### 取余&取商

反转整数还要考虑末尾以1个或多个0结尾的情况，一定会想到两个操作，取余与取商
- 如果不考虑溢出的情况， 就很简单喽！
- 如果考虑溢出的情况，就加一层判断喽！

时间复杂度：O(lg(x))
空间复杂度：O(1)

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
let rev = 0;

    while (x) {
        rev = rev * 10 + x % 10;
        x = ~~(x / 10); // 双按位非，如果x不属于[-2^31, 2^31), 会出错
    }

    if (rev >= 0x7fffffff || rev <= -0x80000000) return 0;

    return rev;
};
```