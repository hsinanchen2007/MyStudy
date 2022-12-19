### 解题思路
 * 试了几次，没有找到规律
 * 暴力法
 * 创建一个 0 ~ n -1的数组
 * 算出下标 t = (cur - 1 + m)%length
 * 每次splice(t, 1)

### 代码

```javascript
/**
 * 试了几次，没有找到规律
 * 暴力法
 * 创建一个 0 ~ n -1的数组
 * 算出下标 t = (cur - 1 + m)%length
 * 每次splice(t, 1)
 * 直到length === 1
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function (n, m) {
    let list = [];
    for(let i = 0; i < n; i++) {
        list[i] = i;
    }

    let cur = 0;
    while(list.length > 1) {
        cur = (cur - 1 + m)%list.length;
        list.splice(cur, 1);
    }

    return list[0];
};
```