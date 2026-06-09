![image.png](https://pic.leetcode-cn.com/40b9b43f1f453be064e383599932a7bc370658ece36aae623339435b0469092f-image.png)

### 解题思路
```js
绝对值（时间戳相减） / 每天的毫秒数
```

### 代码

```javascript
/**
 * @param {string} date1
 * @param {string} date2
 * @return {number}
 */

var daysBetweenDates = function(date1, date2) {
  return Math.abs( (+new Date(date1)) - (+new Date(date2)) ) / (24 * 60 * 60 * 1000);
};
```