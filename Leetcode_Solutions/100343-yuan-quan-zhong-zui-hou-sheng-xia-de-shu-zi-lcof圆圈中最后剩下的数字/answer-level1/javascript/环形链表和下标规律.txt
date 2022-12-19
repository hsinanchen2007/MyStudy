### 解题思路
1. 更新数组和数组长度n;
2. 更新下标 index = (index+m - 1)%n;
3. 当n == 1 时，返回数组的唯一值。

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @return {number}
 */
var lastRemaining = function(n, m) {
    //1. 找到每次删除的小标
    //2. 更新删除后的n和数组
    // m是第三个所以下标是m-1;

    let arr = [],
        i = 0;
    while (i < n) {
        arr.push(i);
        i++;
    }

    let index = (0+m-1)%n;
    while (n > 1) {
        arr.splice(index, 1);
        n -= 1;
        index = (index+m-1)%n;
    }
    return arr[0];
};
```