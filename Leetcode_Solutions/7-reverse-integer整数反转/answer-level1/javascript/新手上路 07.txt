### 解题思路
利用了 三木判断 x 正负，从而达到-号的添加。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let Min = -( 2 ** 31 ), Max = (2 ** 31 - 1);
    let abc = (x > 0 ?  1 : -1) * [...String(x)].filter(x => x !== '-').reverse().join('');
    return abc > Max || abc < Min ? 0 : abc;
};
```