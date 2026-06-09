### 解题思路
遍历一次，使用map保存值。
如果map存在，那么num + 2，并且删除当前key值
如果map不存在，把当前值设置到map中

最后判断看看map中有没有键，如果有则加1

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    const map = new Map();
    let num = 0;
    for (let m of s) {
        if (map.has(m)) {
            map.delete(m);
            num += 2;
        } else {
            map.set(m, 1);
        }
    }
    if (map.size > 0) {
        num += 1;
    }
    return num;
};
```